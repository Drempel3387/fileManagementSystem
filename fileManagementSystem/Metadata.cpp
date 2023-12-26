#include "Metadata.h"

//parameterized constructor
Metadata::Metadata(const Path path, const std::string creationDateTime, const int fileSize)
{
	this->filePath = path;
	this->creationDateTime = creationDateTime;
	this->fileSize = fileSize; 
}

//default constructor
Metadata::Metadata()
{
	this->filePath = Path();	
	this->creationDateTime = "";
	this->fileSize = 0;
}

Path Metadata::getPath() const 
{
	return filePath; 
}

std::string Metadata::getCreationDate() const
{
	return creationDateTime; 
}

int Metadata::getFileSize() const
{
	return fileSize;
}

void Metadata::setPath(const Path path)  
{
	this->filePath = path;  
}

void Metadata::setFileSize(const int)
{
	this->fileSize = fileSize;
}
