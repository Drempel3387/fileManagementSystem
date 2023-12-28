#pragma once
#include "File.h"
#include <fstream>
#include <iostream>
#include <string>

//construct a new file
File::File(const std::string fileName, const std::string creationDateTime, const std::string contents, const Path path) :  metadata(fileName, creationDateTime, path, getSize()) 
{
	this->contents = contents;
	createFile(); 
}

//construct from an existing file
File::File(const File& file)
{
	this->contents = file.contents;
	this->metadata = file.getMetadata(); 
}

//default constructor
File::File(): contents(""), metadata() {}

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

//create a file
void File::createFile()
{
	//create file
	std::ofstream file;
	file.open(fileDescriptor());  
	file << contents; 

	file.close();
}

//returns size of the file
int File::getSize()
{
	//open file
	std::ifstream file;
	file.open(fileDescriptor());  
	
	if (!file.is_open())
		return FILE_SIZE_ERROR;
	
	//get size	
	file.seekg(0, std::ios::end);
	int size = file.tellg();
	file.close();	

	return size;
}

//file location descriptor
std::string File::fileDescriptor()
{
	return (metadata.getPath().getPath() + metadata.getName());
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

