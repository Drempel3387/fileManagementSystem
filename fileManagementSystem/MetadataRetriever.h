#pragma once
#include "Path.h"
class MetadataRetriever
{
private:
	Path path; //path to the file 
public:
	MetadataRetriever(const Path& path); //constructor 

	//getters and setters
	Path getPath() const; //get the path to the file
	void setPath(const Path& path); //set the path to the file

	//overrides
	virtual std::string getCreationDateTime(const Path& path) = 0; 
	virtual size_t getFileSize(const Path& path) = 0;
};

