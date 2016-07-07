#include <DataHandler.hpp>
#include <MotionMagnification.hpp>

int main()
{
	DataHandler dataHandler("baby.mp4");
	MotionMagnification magnify;
	
	magnify.process( dataHandler );

}
