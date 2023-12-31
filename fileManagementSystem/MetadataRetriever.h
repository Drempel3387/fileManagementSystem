#pragma once
#include "Path.h"
#include <string>
#include <memory>
class MetadataRetriever
{
private:
protected:
	Path path; //the path to the file
public:
	//getters and setters
	Path getPath() const; //get the path to the file
	void setPath(const Path& path); //set the path to the file

	static std::shared_ptr<MetadataRetriever> create(const Path& path); //create a metadata retriever based on the OS

	//overrides
	virtual std::string getCreationDateTime() = 0; 
	virtual size_t getFileSize() = 0;
};

