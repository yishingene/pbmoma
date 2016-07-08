/* TemporalFilter.hpp
 * Author: Silvia-Laura Pintea
 */

#ifndef TEMPORALFILTER_H_
#define TEMPORALFILTER_H_

#include <iostream>
#include <vector>
#include <complex>

#include <unsupported/Eigen/FFT>
#include <Eigen/Core>

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
	protected: 
		std::size_t size_; /// Temporal window size.
		std::size_t step_; /// Frame step between the temporal windows.
		Video buffer_; /// The video buffer for the temporal window.
};

/// Ideal bandpass filter. 
class IdealFilter : public TemporalFilter
{
	public:
		typedef Eigen::Matrix<Eigen::FFT<float>::Complex, Eigen::Dynamic, Eigen::Dynamic> Fourier;

		IdealFilter(std::size_t fps = 1, float lowFreq = .5f, float highFreq = .75f)
		: fps_(fps),
		  lowFreq_(lowFreq),
		  highFreq_(highFreq) 
		{}

		virtual ~IdealFilter() {}

		virtual Frame filter(const Frame &input) override;	
	protected:
		std::size_t fps_; /// Frames per second.
		float lowFreq_; /// The low frequency threshold.
		float highFreq_; /// The hight frequency threshold.
		Eigen::FFT<float> fft_; /// The Fast Fourier Transform.		
};

/// Ideal bandpass filter over temporal windows.
class IdealFilterWindowed : public IdealFilter
{ 
	public:
		IdealFilterWindowed(std::size_t size=2, std::size_t step=1, std::size_t fps = 1, float lowFreq = .5f, float highFreq = .75f) 
		: window_( SlidingWindow(size, step) ),
		  IdealFilter(fps, lowFreq, highFreq)	
		{}

		virtual ~IdealFilterWindowed() {}

		Frame windowFilter(const TemporalFilter::Frame &&input, const std::function<Frame(const Frame&)> &function=nullptr);
	protected:
		SlidingWindow window_; /// The temporal sliding window.
};

#endif
