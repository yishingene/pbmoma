/* DataHandler.cpp
 * Author: Silvia-Laura Pintea
 */

#include "DataHandler.hpp"

cv::VideoCapture DataHandler::initVideo()
{
	cv::VideoCapture capture(videoPath_); 
	if(!capture.isOpened())
	{
		std::cerr<<"[DataHandler::readVideo] Unable to read video "<<videoPath_;
	}
	return capture;
}
