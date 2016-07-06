/* DataHandler.hpp
 * Author: Silvia-Laura Pintea
 */

#ifndef DATAHANDLER_H_
#define DATAHANDLER_H_

#include <iostream>
#include <vector>
#include <string>

#include <Eigen/Core>

/// Reading and writing of data.
class DataHandler
{
	typedef Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic> Frame;
	typedef std::vector<Frame> Video;
	public:
		DataHandler(const std::string &videoPath)
		: videoPath_(videoPath)
		{}

		virtual ~DataHandler(){}

		Video readVideo();
	private:
		std::string videoPath_;	 /// Path to the video location.	
};

#endif
