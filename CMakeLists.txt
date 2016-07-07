#PROJECT TO BE BUILT_______________________________________________________ 
# Prefix for install [?]
SET(HOME_DIR /home/laly CACHE PATH "Home directory")
SET(CMAKE_INSTALL_PREFIX ${HOME_DIR}/Work/pbmoma CACHE PATH "Prefix path to where stuff is")
SET(SRC ${CMAKE_INSTALL_PREFIX}/src CACHE PATH "Location of the siources")
SET(EXE ${CMAKE_INSTALL_PREFIX}/build CACHE PATH "Location of the binary files")

PROJECT(pbmoma)

include(CheckCXXCompilerFlag)
SET( CMAKE_CXX_COMPILER "g++" )
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)

include(FindOpenMP)
if(OPENMP_FOUND)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

#if(COMPILER_SUPPORTS_CXX11)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
#elseif(COMPILER_SUPPORTS_CXX0X)
#	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
#else()
#    message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
#endif()
##################################################################################### 
### REQUIRED STUFF ################################################################## 
##################################################################################### 
cmake_minimum_required(VERSION 2.6)
if(COMMAND cmake_policy)
	cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)

#find_package(OpenMP)
#if(OPENMP_FOUND)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")
#endif()

#SET(CMAKE_BUILD_TYPE Release)
##################################################################################### 
### SET LOCAL STUFF ################################################################# 
##################################################################################### 
# Paths to opencv stuff____________________________________________________
SET(OPENCV_INC /usr/local/include CACHE PATH "Location of the OpenCV2.4 headers")
SET(OPENCV_LIB /usr/local/lib CACHE PATH "Location of the OpenCV2.4 libraries")

# Paths to eigen stuff____________________________________________________
SET(EIGEN_INC /usr/include CACHE PATH "Location of the Eigen headers")
SET(EIGEN_LIB /usr/local/lib CACHE PATH "Location of the Eigen libraries?")

# Paths to boost stuff______________________________________________________ 
SET(BOOST_LIB /usr/lib/x86_64-linux-gnu CACHE PATH "Location of boost libraries")
SET(BOOST_INC /usr/include "Boost include directory")

##################################################################################### 
### INCLUDE & LINK STUFF ############################################################ 
##################################################################################### 
INCLUDE_DIRECTORIES( 
	${OPENCV_INC} 
	${BOOST_INC}
	${SRC}/helpers
	${SRC}/pipeline
)
LINK_DIRECTORIES( 
	${OPENCV_LIB} 
	${BOOST_LIB}
)

ADD_LIBRARY(pipeline
	${SRC}/pipeline/MotionMagnification.cpp
	${SRC}/pipeline/TemporalFilter.cpp
	${SRC}/pipeline/DataHandler.cpp
)
#ADD_LIBRARY(helpers  
#	${SRC}/helpers/Auxiliary.cpp
#)

##################################################################################### 
### EXECUTABLE STUFF ################################################################ 
##################################################################################### 
ADD_EXECUTABLE(pbmoma
	${SRC}/main.cpp
)
TARGET_LINK_LIBRARIES(pbmoma
	pipeline
#	helpers
	opencv_core 
	opencv_video
	opencv_calib3d 
	opencv_imgproc 
	opencv_highgui
	opencv_ml
	opencv_features2d
	opencv_legacy
	opencv_flann	
	boost_date_time
	boost_thread
	boost_filesystem
	boost_system
)	

