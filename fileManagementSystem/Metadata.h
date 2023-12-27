#pragma once
#include <string>
class Metadata
{
private:
	std::string name;
	std::string filePath;
	std::string creationDateTime; //YYYY-MM-DD HH:MM:SS
	int fileSize;

public:
	//constructors
	Metadata(const std::string, const std::string, const std::string, const int);
	Metadata();


	//getters
	std::string getPath() const;  
	std::string getCreationDate() const;
	std::string getName() const; 
	int getFileSize() const;

	//setters
	void setPath(const std::string); 
	void setName(const std::string);
	void setFileSize(const int);

};

