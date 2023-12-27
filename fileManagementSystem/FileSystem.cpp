#include "FileSystem.h"
#include <iostream>
#include <string>
 
//initialize the root directory and the current directory
//parent will be null to signify this is the root
FileSystem::FileSystem() : root(rootName, path, nullptr), currentDirectory(root) {}

FileSystem::~FileSystem() {}

Directory FileSystem::getRoot()
{
	return root;
}

Directory FileSystem::getCurrentDirectory()
{
	return currentDirectory;
}

//bool FileSystem::moveTo(const std::string path)
//{
//	std::string nextDirectoryPath;
//
//	//check if the path is empty
//	if (path == EMPTY)
//	{
//		std::cerr << "ERROR: no path provided" << "\n";
//		return false;
//	}
//
//}


