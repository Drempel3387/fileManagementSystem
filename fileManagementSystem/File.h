#pragma once
#include <string>
#include <ostream>
#include "Metadata.h"
class File { 
private:
	//data stored in file
	std::string contents;

	//metadata about file
	Metadata metadata;

	//returns size of the file on disk
	int getSize() const; 

public:
	//could retrieve file size
	static const int FILE_SIZE_ERROR = -1;

	//constructors
	File(const std::string, const std::string, const std::string);

	//getters
	std::string getContents() const;
	Metadata getMetadata() const;

	//setters
	void setContents(const std::string);
	void setMetadata(const Metadata);

	//print to console
	friend std::ostream& operator<<(std::ostream& os, const File& file);
};