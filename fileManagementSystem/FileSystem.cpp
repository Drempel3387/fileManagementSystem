#include "FileSystem.h"
#include <iostream>
#include <string>
Directory* FileSystem::findDirectory(Path& path, Directory& currentDirectory, int count) 
{
	//base case
	if (currentDirectory.getPath() == path)
		return &currentDirectory;

	//recursive case
	std::string nextPathPart = path.getPathParts()[count];  
	for (Directory* child : currentDirectory.getDirectories())
	{
		if (child->getName() == nextPathPart)
		{
			return findDirectory(path, *child, count + 1);
		}
	}
	return nullptr;
}

//initialize the root directory and the current directory
//parent will be null to signify this is the root
FileSystem::FileSystem()
{
	root = new Directory("Root", path, nullptr); 
	currentDirectory = root; 
}

FileSystem::~FileSystem() {}

Directory* FileSystem::getRoot()
{
	return root;
}

Directory* FileSystem::getCurrentDirectory()
{
	return currentDirectory;
}

//move to a specific path
bool FileSystem::moveTo(Path& path)
{
	if (path.getPathParts()[ROOT] != "Root") //the path does not start with "Root"
		return false; //the path is not valid

	Directory* newDirectory = findDirectory(path, *root, START);  
	if (newDirectory != nullptr)
	{
		currentDirectory = newDirectory; 
		return true;
	}//the path was found "exists"

	return false;//the path was not found "does not exist"
}

//move into a child directory
bool FileSystem::moveTo(const std::string name) 
{
	for (Directory* child : currentDirectory->getDirectories())
		if (child->getName() == name) 
		{
			currentDirectory = child; 
			return true; 
		}
	return false;
}

//move back to the parent directory
bool FileSystem::moveBack()  
{
	if (currentDirectory->getParent() != nullptr) //if the current directory is not the root
	{
		currentDirectory = currentDirectory->getParent();
		return true;
	}
	return false;
}




