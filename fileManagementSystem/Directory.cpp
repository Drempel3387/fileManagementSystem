#include "Directory.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

//parameterized constructor
Directory::Directory(const std::string& name, const Path& path, std::shared_ptr<Directory> parent): name(name), path(path), parent(parent) 
{
	directories = std::vector<std::shared_ptr<Directory>>();   
	files = std::vector<std::shared_ptr<File>>(); 
}

//default constructor 
Directory::Directory() : name(""), path(""), parent(nullptr) {} 

//used for comparing directories
Directory::Directory(const std::string& name) : name(name), path(""), parent(nullptr) {}

//destructor
Directory::~Directory() {}

//getters
std::string Directory::getName() const
{
	return this->name;
}

std::vector<std::shared_ptr<File>> Directory::getFiles() const
{
	return this->files;
}

std::vector<std::shared_ptr<Directory>> Directory::getDirectories() const 
{
	return this->directories;
}

Path Directory::getPath() const
{
	return this->path;
}

std::shared_ptr<Directory> Directory::getParent() const
{
	return parent; 
} 

//setters
void Directory::setName(const std::string& name)
{
	this->name = name;
}

void Directory::setPath(const Path& path)
{
	this->path = path;
}

//add file to the directory
bool Directory::addFile(const std::shared_ptr<File> newFile) 
{
	//do not allow duplicate files
	//meaning files with the same name in the same directory
	if (searchFile(newFile->getName())) 
		return false;

	this->files.push_back(newFile);
	return true;
}

//add directory to the directory
bool Directory::addDirectory(const std::shared_ptr<Directory> newDirectory) 
{
	//do not allow duplicate directories 
	//meaning directories with the same name in the same directory
	if (searchDirectory((*newDirectory).getName()))   
		return false;

	this->directories.push_back(newDirectory);    
	return true; 
}

//remove file from the directory if it exists
//returns true if file was removed, false if file was not removed
bool Directory::removeFile(const std::shared_ptr<File> file) 
{
	auto it = std::find(files.begin(), files.end(), file);
	if (it != files.end()) {
		files.erase(it);
		return true;
	}
	return false;
}

//remove directory from the directory if it exists
//returns true if directory was removed, false if directory was not removed
bool Directory::removeDirectory(const std::shared_ptr<Directory> directory)
{
	auto it = std::find(directories.begin(), directories.end(), directory);
	if (it != directories.end()) {
		directories.erase(it);
		return true;
	}
	return false;
}

//search for a file in the directory
std::shared_ptr<File> Directory::searchFile(const std::string& name)
{
	for (std::shared_ptr<File> file: files) 
		if(file->getName() == name)//file with matching name in same directory found 
			return file; 

	return nullptr; //file not found
}

//search for a directory in the directory
std::shared_ptr<Directory> Directory::searchDirectory(const std::string& name) 
{
	for (std::shared_ptr<Directory> directory : directories) 
		if (directory->getName() == name)//directory with matching name in same directory found
			return directory;  

	return nullptr; //directory not found
}

//print all files in the directory
void Directory::printFiles() const
{
	for (std::shared_ptr<File> file : files)
		std::cout << file->getName() << std::endl;    
}

//print all directories in the directory
void Directory::printDirectories() const
{
	for (std::shared_ptr<Directory> directory : directories)
		std::cout << directory->getName() << std::endl;    
}

//overload == operator
bool Directory::operator==(const Directory& other) const
{
	return (this->name == other.name);
}



