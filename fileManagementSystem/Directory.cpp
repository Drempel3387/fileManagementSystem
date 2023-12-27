#include "Directory.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

//parameterized constructor
Directory::Directory(const std::string name)
{
	this->name = name;
}

//default constructor
Directory::Directory()
{
	this->name = "";
}

//destructor
Directory::~Directory()
{
}

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

//add file to the directory
bool Directory::addFile(const File newFile)
{
	//do not allow duplicate files
	if (std::find(files.begin(), files.end(), newFile) != files.end())
		return false;

	this->files.push_back(newFile);
	return true;
}

//add directory to the directory
bool Directory::addDirectory(const Directory newDirectory)
{
	//do not allow duplicate directories 
	if (std::find(directories.begin(), directories.end(), newDirectory) != directories.end()) 
		return false;

	this->directories.push_back(newDirectory);
	return true;
}

//remove file from the directory
bool Directory::removeFile(const File file)
{
	for (int i = 0; i < files.size(); i++)
	{
		if (files[i].getMetadata().getPath() == path)
		{
			files.erase(files.begin() + i);
			return true;
		}
	}
	return false;
}

//remove directory from the directory
bool Directory::removeDirectory(const Directory directory)
{
	for (int i = 0; i < directories.size(); i++)
	{
		if (directories[i].getPath() == path)
		{
			directories.erase(directories.begin() + i);
			return true;
		}
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






