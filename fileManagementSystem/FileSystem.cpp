#include "FileSystem.h"
#include <iostream>
#include <string>

FileSystem::FileSystem()
{
	this->root = Directory(rootName); //create the root directory
}

FileSystem::~FileSystem()
{
}

Directory FileSystem::getRoot()
{
	return this->root;
}

