#pragma once
#include "File.h"
#include <fstream>
#include <string>

//constructor
File::File(const std::string fileName, const std::string creationDateTime, const std::string contents)
{
	this->contents = contents;
	this->metadata = Metadata(fileName, creationDateTime, );
}

//getters
std::string File::getContents() const
{
	return contents;
}

Metadata File::getMetadata() const
{
	return metadata;
}

//setters
void File::setContents(const std::string contents)
{
	this->contents = contents;
}

void File::setMetadata(const Metadata metadata)
{
	this->metadata = metadata;
}

//returns size of the file on disk
int File::getSize() const
{
	//open file
	std::ifstream file;
	file.open(metadata.getFileName());
	if (!file.is_open())
		return FILE_SIZE_ERROR;
	
	//get size	
	file.seekg(0, std::ios::end);
	int size = file.tellg();
	file.close();	

	return size;
}

//print to console
std::ostream& operator<<(std::ostream& os, const File& file)
{
	os << "File Name: " << file.metadata.getFileName() << std::endl;
	os << "Creation Date: " << file.metadata.getCreationDate() << std::endl;
	os << "File Size: " << file.metadata.getFileSize() << std::endl;
	os << "Contents: " << file.contents << std::endl;
	return os;
}

