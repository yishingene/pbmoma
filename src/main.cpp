#include <DataHandler.hpp>
#include <MotionMagnification.hpp>
#include <TemporalFilter.hpp>
#include <cmath>
#include <array>

int main()
{

/*
	DataHandler dataHandler("baby.mp4");
	MotionMagnification magnify;
	
	magnify.process( dataHandler );

*/

	std::size_t fps = 10;
	std::size_t secs = 3;
	std::size_t n = fps * secs;
	std::array<float, 30> ts = 
		{0.        ,  0.10344828,  0.20689655,  0.31034483,  0.4137931 ,
		0.51724138,  0.62068966,  0.72413793,  0.82758621,  0.93103448,
		1.03448276,  1.13793103,  1.24137931,  1.34482759,  1.44827586,
		1.55172414,  1.65517241,  1.75862069,  1.86206897,  1.96551724,
		2.06896552,  2.17241379,  2.27586207,  2.37931034,  2.48275862,
		2.5862069 ,  2.68965517,  2.79310345,  2.89655172,  3.        };
	float noise = 4.0f;
	std::array<float, 30> fq1, fq2, fq3, data;

	for(std::size_t i=0; i<30; ++i)
	{
		fq1[i] = std::sin(ts[i] * 2.0f * M_PI * 1.0f);
		fq2[i] = std::sin(ts[i] * 2.0f * M_PI * 7.0f);
		fq3[i] = std::sin(ts[i] * 2.0f * M_PI * 12.0f);
		data[i] = fq1[i] * 1.0f + fq2[i] * 1.0f + fq3[i] + noise;
	}
	
	IdealFilterWindowed window(60, 1, fps, 4.0f, 9.0f); 
	window.addFrame(data);
	TemporalFilter Frame output = window.filterWindow(data);
	
	std::cout<<output.col(0)<<std::endl;
}
