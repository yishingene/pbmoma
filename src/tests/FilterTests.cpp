// #define CATCH_CONFIG_MAIN -- only once
#include <DataHandler.hpp>
#include <MotionMagnification.hpp>
#include <TemporalFilter.hpp>
#include <cmath>
#include <array>

#include <catch.hpp>

TemporalFilter::Video
defineInputData(std::size_t fps, std::size_t sec)
{
	std::array<float, 30> ts = 
		{0.        ,  0.10344828,  0.20689655,  0.31034483,  0.4137931 ,
		0.51724138,  0.62068966,  0.72413793,  0.82758621,  0.93103448,
		1.03448276,  1.13793103,  1.24137931,  1.34482759,  1.44827586,
		1.55172414,  1.65517241,  1.75862069,  1.86206897,  1.96551724,
		2.06896552,  2.17241379,  2.27586207,  2.37931034,  2.48275862,
		2.5862069 ,  2.68965517,  2.79310345,  2.89655172,  3.        };
	float noise = 4.0f;
	std::array<float, 30> fq1, fq2, fq3;
	
	TemporalFilter::Video data;
	data.reserve(sec * fps);
	for(std::size_t i=0; i<sec*fps; ++i)
	{
		fq1[i] = std::sin(ts[i] * 2.0f * M_PI * 1.0f);
		fq2[i] = std::sin(ts[i] * 2.0f * M_PI * 7.0f);
		fq3[i] = std::sin(ts[i] * 2.0f * M_PI * 12.0f);
	
		TemporalFilter::Frame dataI = TemporalFilter::Frame(1,1);
		float val = fq1[i] * 1.0f + fq2[i] * 1.0f + fq3[i] + noise;

		dataI.setConstant(val);
		data.emplace_back(dataI);
	}

	std::cout<<"Input Data: ";
	for(const auto& d : data)
	{
		std::cout<<d<<" ";
	}
	std::cout<<std::endl;
	return data;
}

TemporalFilter::Video 
testIdealWindowed(TemporalFilter::Video &data, std::size_t bufferSize, std::size_t fps, std::size_t step, std::size_t sec, float lowFreq, float highFreq)
{
	IdealFilterWindowed window(bufferSize, step, fps, lowFreq, highFreq); 
	TemporalFilter::Video output = window.windowFilter(data);

	std::cout<<"Filtered Output:";
	for(const auto& o : output){
		std::cout<<o<<" ";
	}
	std::cout<<std::endl;
	return output;
}

TEST_CASE("IdealFilterWindowed", "[idealwindowed]" ) 
{
	std::size_t bufferSize = 10; 
	std::size_t fps = 10; 
	std::size_t step = 1; 
	std::size_t sec = 3;
	float lowFreq = 4.0f; 
	float highFreq = 9.0f;

	TemporalFilter::Video data = defineInputData(fps, sec);
	TemporalFilter::Video output = testIdealWindowed(data, bufferSize, fps, step, sec, lowFreq, highFreq); 
	
    REQUIRE( output.size() == 21 );
    REQUIRE( output[0](0,0) == Approx(-0.363496) );
    REQUIRE( output[1](0,0) == Approx(-0.214414) );
    REQUIRE( output[2](0,0) == Approx(0.447191) );
    REQUIRE( output[3](0,0) == Approx(0.209622) );
    REQUIRE( output[4](0,0) == Approx(-0.562196) );
    REQUIRE( output[5](0,0) == Approx(-0.159162) );
    REQUIRE( output[6](0,0) == Approx(0.716247) );
    REQUIRE( output[7](0,0) == Approx(0.16722) );
    REQUIRE( output[8](0,0) == Approx(-0.761685) );
    REQUIRE( output[9](0,0) == Approx(-0.121165) );
    REQUIRE( output[10](0,0) == Approx(0.746534) );
    REQUIRE( output[11](0,0) == Approx(-0.00254974) );
    REQUIRE( output[12](0,0) == Approx(-0.776681) );
    REQUIRE( output[13](0,0) == Approx(0.0531634) );
    REQUIRE( output[14](0,0) == Approx(0.740231) );
    REQUIRE( output[15](0,0) == Approx(-0.0599324) );
    REQUIRE( output[16](0,0) == Approx(-0.593543) );
    REQUIRE( output[17](0,0) == Approx(0.130786) );
    REQUIRE( output[18](0,0) == Approx(0.483627) );
    REQUIRE( output[19](0,0) == Approx(-0.155221) );
    REQUIRE( output[20](0,0) == Approx(-0.395389) );
}

TEST_CASE("Dummy", "[dummy]" ) 
{
	std::cout<<"HEY DUMMY>"<<std::endl;
}
