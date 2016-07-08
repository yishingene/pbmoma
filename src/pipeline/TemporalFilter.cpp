/* TemporalFilter.cpp
 * Author: Silvia-Laura Pintea
 */

#include <opencv2/opencv.hpp>

#include "TemporalFilter.hpp"

/// Adds the given frame to the sliding window buffer.
void SlidingWindow::addFrame(const Frame &&frame)
{
	buffer_.emplace_back(frame);
}

/// Gets the current temporal window from the buffer.
SlidingWindow::Frame SlidingWindow::getWindow()
{
	Frame output(buffer_[0].cols() * buffer_[0].rows(), size_); // rows x cols

	if(buffer_.size() >= size_ )
	{
		for(std::size_t i=0; i<size_; ++i)
		{
			output.col(i) = Eigen::Map<Frame>(buffer_[i].data(), output.cols(), 1);
			buffer_.erase(buffer_.begin()); 
		}
	}
	return output;
}
		
/// From EVM-Matlab Ideal filter implementation.
TemporalFilter::Frame IdealFilter::filter(const TemporalFilter::Frame &input)
{
	Frame output(input.rows(), input.cols());
	
	// Get the FFT from the input.
	Fourier fft = Fourier::Zero(input.rows(), input.cols());
	fft_.fwd(fft.data(), input.data(), -1);

	// Define frequency: (1:n)-1 / (nd) and mask it with the thresholds. 
	for(std::size_t i=0; i<input.cols(); ++i) // Column-wise storage of data, Eigen-style.
	{
		float freq = static_cast<float>(i) / ( static_cast<float>(input.cols()) * 1.0/static_cast<float>(fps_) );
		if(!(freq >= lowFreq_ && freq <= highFreq_))
		{
			fft.col(i) = fft.col(i) * 0.0f;
		}
	}

	//	Invert back the FFT.
	fft_.inv(output.data(), fft.data(), -1); // Automatic size determination.	
	return output;
}

TemporalFilter::Frame IdealFilterWindowed::windowFilter(
	const TemporalFilter::Frame &&input, 
	const std::function<Frame(const Frame&)> &function)
{
	window_.addFrame(std::move(input));
	Frame data = window_.getWindow();

	if(function != nullptr)
	{	
		return function(filter(data));
	}
	return filter(data); 
}
