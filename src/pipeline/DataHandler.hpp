/* DataHandler.hpp
 * Author: Silvia-Laura Pintea
 */

#ifndef DATAHANDLER_H_
#define DATAHANDLER_H_

#include <iostream>
#include <vector>
#include <string>

#include <eigen2/Eigen/Core>

/// Reading and writing of data.
class DataHandler
{
	public:
		typedef Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic> Frame;
		typedef std::vector<Frame> Video;

		DataHandler(const std::string &videoPath)
		: videoPath_(videoPath)
		{}

		virtual ~DataHandler(){}

		Video readVideo();
	private:
		std::string videoPath_;	 /// Path to the video location.	
};

#endif
