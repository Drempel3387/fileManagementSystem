#pragma once
#include <string>
#include "Path.h"
class Metadata
{
private:
	std::string name;
	Path path; 
	std::string creationDateTime; //YYYY-MM-DD HH:MM:SS TODO: import time library
	int fileSize;

public:
	//constructors
	Metadata(const std::string&, const std::string&, const Path& path, const int&);
	Metadata();

	//getters
	Path getPath() const;   
	std::string getCreationDate() const;
	std::string getName() const; 
	int getFileSize() const;

	//setters
	void setPath(const Path&);   
	void setName(const std::string&);
	void setFileSize(const int&);

};

