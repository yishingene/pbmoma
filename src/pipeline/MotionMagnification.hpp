/* MotionMagnification.hpp
 * Author: Silvia-Laura Pintea
 */

#ifndef MOTIONMAGNIFICATION_H_
#define MOTIONMAGNIFICATION_H_

#include <iostream>
#include <vector>
#include <string>

#include <DataHandler.hpp>

/// Reading and writing of data.
class MotionMagnification
{
	public:
		typedef Eigen::Matrix<float, 1, Eigen::Dynamic> Frame; // One frame reshaped as row.
		typedef Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic> ReshapedVideo; // Multiple frames, each one row.
		typedef std::vector<Frame> Video; // Vector of frames, each one row. 
 
		MotionMagnification(){}

		virtual ~MotionMagnification(){}

		void process(DataHandler &capture);
		void writeFramesToDisk(const Video &video);
	private:
};

#endif
