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

	//returns size of the file 
	int getSize(const std::string) const;

	//create a file
	void createFile(const std::string, const std::string);

public:
	//could not retrieve file size
	static const int FILE_SIZE_ERROR = -1;

	//construct a new file
	File(const std::string, const std::string, const std::string, const std::string); 

	//construct a file from an existing file
	File(const std::string, const std::string); 

	//default constructor
	File();

	//getters
	std::string getContents() const;
	Metadata getMetadata() const;

	//setters
	void setContents(const std::string);
	void setMetadata(const Metadata);

	//print to console
	friend std::ostream& operator<<(std::ostream& os, const File& file);

	//overloads
	bool operator==(const File& other) const;
};