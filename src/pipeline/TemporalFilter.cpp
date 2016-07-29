/* TemporalFilter.cpp
 * Author: Silvia-Laura Pintea
 */

#include <opencv2/opencv.hpp>

#include "TemporalFilter.hpp"
	
/**
 * Convert a reshaped video where each row is one frame to a vector of frames (each one row). 
 */
SlidingWindow::Video 
SlidingWindow::convertReshapedVideoToVideo(SlidingWindow::ReshapedVideo &input)
{
	Video outputVideo;
	outputVideo.reserve(input.rows());

	for(std::size_t row=0; row<input.rows(); ++row)
	{
		outputVideo.emplace_back(input.row(row));
	} // Over video frames.

	return outputVideo;
}

/**
 * Adds a given frame to the sliding window buffer.
 */
void SlidingWindow::addFrame(const Frame &&frame)
{
	assert(frame.rows() == 1); // The frames are rows 
	buffer_.emplace_back(frame);
}

/**
 * Gets the current temporal window from the buffer.
 */
SlidingWindow::ReshapedVideo SlidingWindow::getWindow()
{
	ReshapedVideo output;
	if(buffer_.size() >= size_ )
	{
		output.resize(size_, buffer_[0].cols() * buffer_[0].rows()); // rows x cols
		for(std::size_t i=0; i<size_; ++i)
		{
			output.row(i) = Eigen::Map<Frame>(buffer_[i].data(), output.cols(), 1);
		}
			
		// At each iteration just remove the last one.	
		buffer_.erase(buffer_.begin()); 
	}
	return output;
}

/**
 * Gets the FFT frequencies to be masked.
 * f = [0, 1, ...,   n/2-1,     -n/2, ..., -1] / (d*n)   if n is even
 * f = [0, 1, ..., (n-1)/2, -(n-1)/2, ..., -1] / (d*n)   if n is odd
 */
std::vector<float>
IdealFilter::getFFTFreq(std::size_t n)
{
	std::vector<float> fftFreq(n, 0);
	for(std::size_t i=1; i<n; ++i)
	{
		if(n%2 == 0)
		{
			fftFreq[i] = static_cast<float>(i <= (n/2 - 1)? i : static_cast<float>(i)-static_cast<float>(n));
		}
		else
		{
			fftFreq[i] = static_cast<float>(i <= (n-1)/2? i : static_cast<float>(i)-static_cast<float>(n));
		}
		fftFreq[i] /= (static_cast<float>(n) * 1.0/static_cast<float>(fps_));
	}
	return fftFreq;
}

		
/**
 * Ideal filter implementation over time (cols in the ReshapedVideo). 
 * It sets certain pixels to 0 in the Fourier space.
 */
TemporalFilter::ReshapedVideo 
IdealFilter::filter(const TemporalFilter::ReshapedVideo &input)
{
	ReshapedVideo output(input.rows(), input.cols());
	
	// Define frequency: (1:n)-1 / (nd) and mask it with the thresholds. 
	std::vector<float> fftFreq = getFFTFreq(input.rows());

	// Get the FFT.
	Fourier fft = Fourier(input.rows(), input.cols());
	for(std::size_t col=0; col<input.cols(); ++col) 
	{
		// Fourier transform per col.
		fft_.fwd(fft.col(col).data(), input.col(col).data(), input.rows());

		// Make the rows 0 or not.
		for(std::size_t row=0; row<input.rows(); ++row)
		{
			if(!(std::abs(fftFreq[row]) >= lowFreq_ && std::abs(fftFreq[row]) <= highFreq_))
			{
				fft(row,col) = Eigen::FFT<float>::Complex(0);
			}
		}
	
		// Convert it back or not.
		fft_.inv(output.col(col).data(), fft.col(col).data(), input.rows()); // Automatic size determination.	

	} // Over time per pixel
	return output;
}

/**
 * For each window apply the temporal filter and then convert it back to video frames.
 */
TemporalFilter::Video IdealFilterWindowed::windowFilter(
	TemporalFilter::Video &input, 
	const std::function<Frame(const Frame&)> &function)
{
	Video output;
	while(!input.empty())
	{
		window_.addFrame(std::move(input[0]));
		ReshapedVideo data = window_.getWindow();
		input.erase(input.begin());

		if(data.size())
		{
			ReshapedVideo filtered = filter(data);

			// Emplace the video frames back into the output.
			Video tovideo = window_.convertReshapedVideoToVideo(filtered);

			// Only the first video frame get processed and added back.
			if(function != nullptr)
			{	
				output.emplace_back(function(tovideo[0]));
			}
			else
			{
				output.emplace_back(tovideo[0]);
			}
		}
	}
	return output;
}
