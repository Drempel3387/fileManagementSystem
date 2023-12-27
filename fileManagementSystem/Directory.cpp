#include "Directory.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

//parameterized constructor
Directory::Directory(const std::string name, const std::string path, Directory* parent) : name(name), path(path), parent(parent) {}

//default constructor 
Directory::Directory() : name(""), path(""), parent(nullptr) {} 

//destructor
Directory::~Directory() {}

//getters
std::string Directory::getName() const
{
	return this->name;
}

std::vector<File> Directory::getFiles() const
{
	return this->files;
}

std::vector<Directory> Directory::getDirectories() const
{
	return this->directories;
}

std::string Directory::getPath() const
{
	return this->path;
}

Directory* Directory::getParent() const
{
	return parent; 
}

//setters
void Directory::setFiles(const std::vector<File> files) 
{
	this->files = files;
}

void Directory::setName(const std::string name)
{
	this->name = name;
}

void Directory::setDirectories(const std::vector<Directory> directories)
{
	this->directories = directories;
}

void Directory::setPath(const std::string path)
{
	this->path = path;
}

void Directory::setParent(Directory* parent)
{
	this->parent = parent; 
}

//add file to the directory
bool Directory::addFile(const File& newFile)
{
	//do not allow duplicate files
	//meaning files with the same name in the same directory
	if (searchFile(newFile.getMetadata().getName()))
		return false;

	this->files.push_back(newFile);
	return true;
}

//add directory to the directory
bool Directory::addDirectory(const Directory& newDirectory)
{
	//do not allow duplicate directories 
	//meaning directories with the same name in the same directory
	if (searchDirectory(newDirectory.getName()))  
		return false;

	this->directories.push_back(newDirectory);
	return true;
}

//remove file from the directory if it exists
//returns true if file was removed, false if file was not removed
bool Directory::removeFile(const File& file) 
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
bool Directory::removeDirectory(const Directory& directory)
{
	auto it = std::find(directories.begin(), directories.end(), directory);
	if (it != directories.end()) {
		directories.erase(it);
		return true;
	}
	return false;
}

//search for a file in the directory
File* Directory::searchFile(const std::string name)
{
	for (File& file: files)
		if(file.getMetadata().getName() == name)//file with matching name in same directory found
			return &file;

	return nullptr; //file not found
}

//search for a directory in the directory
Directory* Directory::searchDirectory(const std::string name)
{
	for (Directory& directory : directories)
		if (directory.getName() == name)//directory with matching name in same directory found
			return &directory;

	return nullptr; //directory not found
}

//print all files in the directory
void Directory::printFiles() const
{
	for (File file : files)
		std::cout << file.getMetadata().getName() << std::endl;  
}

//print all directories in the directory
void Directory::printDirectories() const
{
	for (Directory directory : directories)
		std::cout << directory.getName() << std::endl; 
}

//overload == operator
bool Directory::operator==(const Directory& other) const
{
	return (this->name == other.name);
}



