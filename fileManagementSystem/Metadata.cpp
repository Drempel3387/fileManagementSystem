#include "Metadata.h"

//parameterized constructor
Metadata::Metadata(const std::string& name, const std::string& creationDateTime, const Path& path, const int& fileSize)
{
	this->path = path;  
	this->name = name; 
	this->creationDateTime = creationDateTime;
	this->fileSize = fileSize;
}

//default constructor
Metadata::Metadata(): name(""), creationDateTime(""), path(""), fileSize(0) {} 

Path Metadata::getPath() const  
{
	return path;  
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

void Metadata::setPath(const Path& path)   
{
	this->path = path;  
}

void Metadata::setFileSize(const int& fileSize)
{
	this->fileSize = fileSize;
}

void Metadata::setName(const std::string& name)
{
	this->name = name;
}

