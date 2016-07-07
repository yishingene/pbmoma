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
			output.col(i) = Eigen::Map<Frame>(buffer_[i], output.cols(), 1);
			buffer_.erase(buffer_.begin()); 
		}
	}
	return output;
}
		
IdealFilter::Frame IdealFilter::filter(const IdealFilter::Frame &input)
{
	Frame output(input.rows(), input.cols());
	
	for(std::size_t col=0; col<input.cols(); ++col)
	{
		// Define frequency
		Fourier frequencies(input.rows(), 1);
		frequencies = fft_.fwd(input.col(col));

		// Bandpass the frequencies:
		frequencies = frequencies * (frequencies > lowFreq_ && frequencies < highFreq_);		

		//	Inver them back
		fft_.inv(output.col(col), frequencies);	
	}

	return output;
}



