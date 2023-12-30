#include "Metadata.h"

//parameterized constructor
Metadata::Metadata(const Path& path, std::shared_ptr<MetadataRetriever> retriever) 
{
	this->name = path.getPart(path.getPartsCount() - 1); //get the last part of the path (the name of the file)
	this->path = path; 
	this->creationDateTime = retriever->getCreationDateTime(path); 
	this->fileSize = retriever->getFileSize(path); 
}

//default constructor
Metadata::Metadata(): creationDateTime(), path(""), name(""), fileSize(0) {}

Path Metadata::getPath() const  
{
	return path;  
}

std::string Metadata::getCreationDate() const
{
	return creationDateTime; 
}

size_t Metadata::getFileSize() const
{
	return fileSize;
}

void Metadata::setPath(const Path& path)   
{
	this->path = path;  
}

std::string Metadata::getName() const
{
	return name;
}

void Metadata::setName(const std::string& name)
{
	this->name = name;
	path.setPart(path.getPartsCount() - 1, name); //set the last part of the path to the new name of the file
}

void Metadata::setCreationDate(const std::string& creationDateTime)
{
	this->creationDateTime = creationDateTime;
}

void Metadata::setFileSize(const size_t& fileSize) 
{
	this->fileSize = fileSize;
}

