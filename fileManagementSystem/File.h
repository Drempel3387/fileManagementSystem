#pragma once
#include <string>
#include <ostream>
#include "Metadata.h"
class File { 
private:
	//data members
	std::string contents;
	Metadata metadata;

	//private methods
	int getSize() const;
	void createFile();
	std::string fileDescriptor() const;//path + filename

public:
	//could not retrieve file size
	static const int FILE_SIZE_ERROR = -1;

	//constructors
	File(const std::string&, const Metadata&);  
	File(const File&); 
	File();

	//getters
	std::string getContents() const;
	Path getPath() const; 
	std::string getCreationDate() const; 
	std::string getName() const; 
	int getFileSize() const;

	//setters
	void setContents(const std::string);
	void setPath(const Path&);
	void setName(const std::string&);

	//overloads
	friend std::ostream& operator<<(std::ostream& os, const File& file);//print file object to console
	bool operator==(const File& other) const;//compare two files for equality (by path)
};