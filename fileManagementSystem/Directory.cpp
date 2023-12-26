#include "Directory.h"
#include <iostream>
#include <string>
#include <vector>

Directory::Directory(std::string name)
{
	this->name = name;
}

Directory::Directory()
{
	this->name = "";
}

Directory::~Directory()
{
}

std::string Directory::getName()
{
	return this->name;
}

std::vector<File> Directory::getFiles()
{
	return this->files;
}

std::vector<Directory> Directory::getDirectories()
{
	return this->directories;
}

void Directory::setFiles(std::vector<File> files)
{
	this->files = files;
}

void Directory::setName(std::string name)
{
	this->name = name;
}

void Directory::setDirectories(std::vector<Directory> directories)
{
	this->directories = directories;
}



