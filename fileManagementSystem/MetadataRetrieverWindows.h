#pragma once
#ifdef _WIN32
#include "MetadataRetriever.h"
#include "Windows.h"
#include "Path.h"
#include <iostream>
class MetadataRetrieverWindows: public MetadataRetriever
{
private:

public:
	MetadataRetrieverWindows(const Path&);
	
	//overrides
	std::string getCreationDateTime(); 
	size_t getFileSize();
};

#endif // _WIN32 


