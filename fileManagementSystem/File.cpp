#pragma once
#include "File.h"
#include <fstream>
#include <iostream>
#include <string>

//construct a new file
File::File(const Path& path)
{
	this->contents = nullptr;
	this->metadata = Metadata(path, MetadataRetriever::create(path)); 
}

//construct from an existing file
File::File(const File& file)
{
	this->contents = file.contents;
	this->metadata = file.metadata; 
}

//default constructor
File::File(): contents(nullptr), metadata() {}

//getters
Path File::getPath() const 
{
	return metadata.getPath(); 
}

std::string File::getCreationDate() const
{
	return metadata.getCreationDate();
}

std::string File::getName() const
{
	return metadata.getName();
}

size_t File::getFileSize() const
{
	return metadata.getFileSize(); 
}

//setters
void File::setPath(const Path& path)
{
	metadata.setPath(path);
}

void File::setName(const std::string& name)
{
	metadata.setName(name);
}

//print to console
std::ostream& operator<<(std::ostream& os, const File& file)
{
	os << "File Name: " << file.metadata.getName() << std::endl;  
	os << "Creation Date: " << file.metadata.getCreationDate() << std::endl;
	os << "File Size: " << file.metadata.getFileSize() << std::endl;
	os << "Contents: " << file.contents << std::endl;
	return os;
}

//overloads
bool File::operator==(const File& other) const
{
	return (this->metadata.getPath() == other.metadata.getPath());   
}

