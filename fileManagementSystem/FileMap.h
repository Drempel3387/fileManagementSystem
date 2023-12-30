#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include "File.h"

class FileMap
{
private:
	//variables
	std::unordered_map<std::string, std::vector<std::shared_ptr<File>>> fileMap; //maps file names to a vector of files with that nam

public:
	//constructors
	FileMap();
	~FileMap();

	//methods
	void addFile(std::shared_ptr<File> file);
	void removeFile(std::shared_ptr<File> file);
	void removeFile(const std::string& name); 
	bool contains(std::shared_ptr<File> file);
	std::vector<std::shared_ptr<File>> getFiles(const std::string& name); 
	void clear();
	std::vector<std::string> getNames(); 
	size_t getFileCount();  
};

