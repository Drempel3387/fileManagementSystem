#pragma once
#include "File.h"
#include <fstream>
#include <iostream>
#include <string>

//construct a new file
File::File(const std::string& contents, const Metadata& metadata)
{
	this->metadata = metadata; 
	this->contents = contents;
	createFile(); 
}

//construct from an existing file
File::File(const File& file)
{
	this->contents = file.contents;
	this->metadata = file.metadata; 
}

//default constructor
File::File(): contents(""), metadata() {}

//getters
std::string File::getContents() const
{
	return contents;
}

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

int File::getFileSize() const
{
	return getSize();
}

//setters
void File::setContents(const std::string contents)
{
	this->contents = contents;
}

void File::setPath(const Path& path)
{
	metadata.setPath(path);
}

void File::setName(const std::string& name)
{
	metadata.setName(name);
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
int File::getSize() const
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
std::string File::fileDescriptor() const
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

