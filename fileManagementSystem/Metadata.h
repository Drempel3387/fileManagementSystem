#pragma once
#include <string>
#include "Path.h"
class Metadata
{
private:
	Path filePath;
	std::string creationDateTime; //YYYY-MM-DD HH:MM:SS
	int fileSize;

public:
	//constructors
	Metadata(const Path, const std::string, const int);
	Metadata();
	//getters
	Path getPath() const;  
	std::string getCreationDate() const;
	int getFileSize() const;

	//setters
	void setPath(const Path); 
	void setFileSize(const int);

};

