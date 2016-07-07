/* MotionMagnification.cpp
 * Author: Silvia-Laura Pintea
 */

#include <eigen2/Eigen/Core>

#include <TemporalFilter.hpp>
#include "MotionMagnification.hpp"

void MotionMagnification::process(DataHandler &dataHandler)
{
	SlidingWindow window;

	cv::VideoCapture capture = dataHandler.initVideo();
	
	for(;;)
	{
		// Get a new frame from the video.
		cv::Mat intFrame;
        capture >> intFrame; 
        cv::cvtColor(intFrame, intFrame, CV_BGR2GRAY);

cv::imshow("frame", intFrame);
cv::waitKey(0);

		cv::Mat frame;
		intFrame.convertTo(frame, CV_32FC1);
		Frame dataFrame = Eigen::Map<Frame>(reinterpret_cast<float*>(frame.data), frame.rows, frame.cols);

		// Add the frame to the window buffer.		
		window.addFrame(std::move(dataFrame));	
		Video videoWindow = window.getWindow();
		if( videoWindow.empty() ) 	
		{
			continue; 
		}

		// Filter the video window.
    }
}
