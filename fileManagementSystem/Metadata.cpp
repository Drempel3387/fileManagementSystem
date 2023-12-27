#include "Metadata.h"

//parameterized constructor
Metadata::Metadata(const std::string name, const std::string creationDateTime, std::string path, const int fileSize)
{
	this->filePath = path;
	this->name = name;
	this->creationDateTime = creationDateTime;
	this->fileSize = fileSize;
}

//default constructor
Metadata::Metadata(): name(""), creationDateTime(""), filePath(""), fileSize(0) {}

std::string Metadata::getPath() const  
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

std::string Metadata::getName() const
{
	return name;
}

void Metadata::setPath(const std::string path)  
{
	this->filePath = path;  
}

void Metadata::setFileSize(const int)
{
	this->fileSize = fileSize;
}

void Metadata::setName(const std::string name)
{
	this->name = name;
}

