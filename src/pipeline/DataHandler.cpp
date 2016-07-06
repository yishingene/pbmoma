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
		cv::Mat frame;
        capture >> frame; // get a new frame from camera
        cv::cvtColor(frame, frame, CV_BGR2GRAY);

		Frame dataFrame = Eigen::Map<Frame>(frame.rows(), frame.cols(), frame.data());

std::cout<<"One frame:"<<dataFrame<<std::endl;

		dataVideo.emplace_back(dataFrame);	
    }
    return dataVideo;
}

