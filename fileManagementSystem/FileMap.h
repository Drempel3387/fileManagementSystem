#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include "File.h"

class FileMap: public std::unordered_map<std::string, std::vector<File*>> 
{
public:
	//constructors
	FileMap();
	~FileMap();

	//methods
	void addFile(File* file);
	void removeFile(File* file);
	bool contains(File* file);
	std::vector<File*> getFiles(const std::string& name); 
	void printFiles();
};

