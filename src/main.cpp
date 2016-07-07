#include <DataHandler.hpp>

int main()
{
	DataHandler dataHandler("baby.mp4");
	DataHandler::Video video = dataHandler.readVideo();

}
