#pragma once
#include <string>
#include <memory>
#include "MetadataRetriever.h"
#include "Path.h"
class Metadata
{
private:
	Path path; 
	std::string name; 
	std::string creationDateTime; 
	size_t fileSize;

public:
	//constructors
	Metadata(const Path& path, std::shared_ptr<MetadataRetriever> retriever);   
	Metadata();

	//getters
	Path getPath() const;   
	std::string getCreationDate() const;  
	std::string getName() const; 
	size_t getFileSize() const;

	//setters
	void setPath(const Path&);   
	void setName(const std::string&);
	void setCreationDate(const std::string&); 
	void setFileSize(const size_t& fileSize); 

};

