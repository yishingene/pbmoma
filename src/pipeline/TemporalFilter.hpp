/* TemporalFilter.hpp
 * Author: Silvia-Laura Pintea
 */

#ifndef TEMPORALFILTER_H_
#define TEMPORALFILTER_H_

#include <iostream>
#include <vector>

#include <nfft.h>

#include <unsupported/Eigen/FFT>
#include <eigen2/Eigen/Core>

/// For temporally filtering and input video to remove the average non-motion pixels. 
class TemporalFilter
{
	public:
		typedef Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic> Frame;
		typedef std::vector<Frame> Video;

		TemporalFilter(){}

		virtual ~TemporalFilter(){}

		virtual Frame filter(const Frame& input) = 0;
	private:
};

/// Auxiliary class for temporal sliding window to be used in IIR filter.
class SlidingWindow
{
	public:
		typedef Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic> Frame;
		typedef std::vector<Frame> Video;

		SlidingWindow(size_t size = 2, size_t step = 1)
		: size_(size),
		  step_(step)
		{}

		virtual ~SlidingWindow() {}

		void addFrame(const Frame &&frame);	
		Frame getWindow();
	private: 
		std::size_t size_; /// Temporal window size.
		std::size_t step_; /// Frame step between the temporal windows.
		Video buffer_; /// The video buffer for the temporal window.
};

/// Ideal band pass filter. 
class IdealFilter : public TemporalFilter
{
	public:
		typedef Eigen::Matrix<std::complex, Eigen::Dynamic, Eigen::Dynamic> Fourier;

		IdealFilter() {}
		virtual ~IdealFilter() {}

		virtual Frame filter(const &Frame input) override;	
	private:
		std::size_t fps_; /// Frames per second.
		float lowFreq_; /// The low frequency threshold.
		float highFreq_; /// The hight frequency threshold.
		Eigen::FFT<float> fft_; /// The Fast Fourier Transform.		
}

#endif
