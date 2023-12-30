#pragma once
#include "MetadataRetriever.h"
#include "sys/stat.h"
#include "Path.h"
#include <iostream>
class MetadataRetrieverUnix: public MetadataRetriever
{
private:
	//private methods
	struct stat getFileStat(const Path& path); //get the metadata of the file
	std::string convertTimeToString(const time_t& time); //convert the time_t object to a string 
public:
	MetadataRetrieverUnix(const Path& path); 

	std::string getCreationDateTime(const Path& path); //get the creation date of the file 
	size_t getFileSize(const Path& path); //get the size of the file   
};

