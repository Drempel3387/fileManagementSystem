#pragma once
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
	std::string getCreationDateTime(const Path& path); 
	size_t getFileSize(const Path& path);
};


