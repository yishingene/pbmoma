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
			output.row(i) = Eigen::Map<Frame>(buffer_[0].data(), output.cols(), 1);
			buffer_.erase(buffer_.begin()); 
		}
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
	std::vector<float> fftFreq(0, n);
	for(std::size_t i=1; i<n; ++i)
	{
		if(n%2 == 0)
		{
			fftFreq[i] = static_cast<float>(i <= (n/2 - 1)? i : i-n);
		}
		else
		{
			fftFreq[i] = static_cast<float>(i <= (n-1)/2? i : i-n);
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
	
	// Get the FFT from the input.

std::cout<<"here -1"<<std::endl;
	Fourier fft = Fourier(input.rows(), input.cols());

std::cout<<"here 0"<<std::endl;

std::cout<<"here 1"<<std::endl;

	std::vector<float> fftFreq = getFFTFreq(input.cols());

std::cout<<"here 2"<<std::endl;

	// Define frequency: (1:n)-1 / (nd) and mask it with the thresholds. 
	for(std::size_t col=0; col<input.cols(); ++col) 
	{
		// Fourier transform per col.
		fft_.fwd(fft.col(col).data(), input.col(col).data(), input.rows());
		if(!(fftFreq[col] >= lowFreq_ && fftFreq[col] <= highFreq_))
		{
			fft.col(col).setConstant(0);
		} 

		fft_.inv(output.col(col).data(), fft.col(col).data(), input.rows()); // Automatic size determination.	
	} // Over time per pixel

std::cout<<"here 3"<<std::endl;

	//	Invert back the FFT.

std::cout<<"fft-output:"<<output<<std::endl;

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
		input.erase(input.begin());
		ReshapedVideo data = window_.getWindow();

		if(data.size())
		{
std::cout<<"Windowed data:"<<data<<std::endl;

			ReshapedVideo filtered;
			if(function != nullptr)
			{	
				filtered = function(filter(data));
			}
			else
			{
				filtered = filter(data);
			}

			// Emplace the video frames back into the output.
			Video tovideo = window_.convertReshapedVideoToVideo(filtered);
			for(auto &&video : tovideo)
			{
				output.emplace_back(video);
			}
		}
	}
	return output;
}
