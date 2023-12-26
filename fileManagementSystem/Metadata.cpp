#include "Metadata.h"

//parameterized constructor
Metadata::Metadata(const std::string fileName, const std::string creationDateTime, const int fileSize)
{
	this->fileName = fileName;
	this->creationDateTime = creationDateTime;
	this->fileSize = fileSize; 
}

//default constructor
Metadata::Metadata()
{
	this->fileName = "";
	this->creationDateTime = "";
	this->fileSize = 0;
}

std::string Metadata::getFileName() const
{
	return fileName;
}

std::string Metadata::getCreationDate() const
{
	return creationDateTime; 
}

int Metadata::getFileSize() const
{
	return fileSize;
}

void Metadata::setFileName(const std::string)
{
	this->fileName = fileName;
}

void Metadata::setFileSize(const int)
{
	this->fileSize = fileSize;
}
