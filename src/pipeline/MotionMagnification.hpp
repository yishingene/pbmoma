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
		typedef Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic> Frame;
		typedef std::vector<Frame> Video;
 
		MotionMagnification(){}

		virtual ~MotionMagnification(){}

		void process(DataHandler &capture);
	private:
};

#endif
