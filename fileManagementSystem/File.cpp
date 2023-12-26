#pragma once
#include "File.h"
#include <fstream>
#include <iostream>
#include <string>

//construct a new file
File::File(const std::string fileName, const std::string creationDateTime, const std::string contents)
{
	createFile(fileName, contents); 
	this->contents = contents;
	this->metadata = Metadata(fileName, creationDateTime, getSize(fileName));
}

//construct an existing file
File::File(const std::string fileName)
{
	std::ifstream file;
	file.open(fileName);
	if (!file.is_open())
	{
		std::cout << "File does not exist." << std::endl;
		return;
	}

	std::string contents = "";
	std::string line;
	while (std::getline(file, line))
	{
		contents += line;
	}
	file.close();
	this->contents = contents;
	this->metadata = Metadata(fileName, "", getSize(fileName));
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

//create a file
void File::createFile(const std::string fileName, const std::string contents)
{
	//create file
	std::ofstream file;
	file.open(fileName);
	file << contents;
	file.close();
}

//returns size of the file
int File::getSize(const std::string fileName) const
{
	//open file
	std::ifstream file;
	file.open(fileName); 
	
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

