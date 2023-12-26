#pragma once
#include <string>
class Metadata
{
private:
	std::string fileName;
	std::string creationDateTime;
	int fileSize;

public:
	//constructors
	Metadata(const std::string, const std::string, const int);
	Metadata();
	//getters
	std::string getFileName() const;
	std::string getCreationDate() const;
	int getFileSize() const;

	//setters
	void setFileName(const std::string);
	void setFileSize(const int);

};

