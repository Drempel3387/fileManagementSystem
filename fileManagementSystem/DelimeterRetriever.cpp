#include "DelimeterRetriever.h"
std::string DelimeterRetriever::getDelimeter()
{
#ifdef _WIN32
	return "\\";
#else 
	return "/"
#endif 
}