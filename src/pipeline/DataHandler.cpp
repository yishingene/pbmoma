/* DataHandler.cpp
 * Author: Silvia-Laura Pintea
 */

#include <opencv2/opencv.hpp>
#include "DataHandler.hpp"

DataHandler::Video DataHandler::readVideo()
{
	cv::VideoCapture capture(videoPath_); 
	if(!capture.isOpened())
	{
		std::cerr<<"[DataHandler::readVideo] Unable to read video "<<videoPath_;
	}

	Video dataVideo;
    for(;;)
	{
		cv::Mat intFrame;
        capture >> intFrame; // get a new frame from camera
        cv::cvtColor(intFrame, intFrame, CV_BGR2GRAY);
		cv::Mat frame;
		intFrame.convertTo(frame, CV_32FC1);
		Frame dataFrame = Eigen::Map<Frame>(reinterpret_cast<float*>(frame.data), frame.rows, frame.cols);
		dataVideo.emplace_back(dataFrame);	
    }
    return dataVideo;
}

