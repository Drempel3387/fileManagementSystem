#pragma once
#include <string>
#include <ostream>
#include "Metadata.h"
#include "Path.h"
class File { 
private:
	//data members
	std::shared_ptr<std::string> contents; 
	Metadata metadata;

public:

	//constructors
	File(const Path& path);   
	File(const File&); 
	File();

	//getters
	Path getPath() const; 
	std::string getCreationDate() const; 
	std::string getName() const; 
	size_t getFileSize() const; 

	//setters
	void setPath(const Path&);
	void setName(const std::string&);

	//overloads
	friend std::ostream& operator<<(std::ostream& os, const File& file);//print file object to console
	bool operator==(const File& other) const;//compare two files for equality (by path)
};