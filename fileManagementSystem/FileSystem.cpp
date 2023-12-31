#include "FileSystem.h"
#include <iostream>
#include <string>
std::shared_ptr<Directory> FileSystem::findDirectory(Path& path, std::shared_ptr<Directory> currentDirectory, int count)
{
	//base case
	if (currentDirectory->getPath() == path)
		return currentDirectory;

	//recursive case
	std::string nextPathPart = path.getPart(count);   
	for (std::shared_ptr<Directory> child : currentDirectory->getDirectories())  
	{
		if (child->getName() == nextPathPart)
		{
			return findDirectory(path, child, count + 1); 
		}
	}
	return nullptr;
}

//initialize the root directory and the current directory
//parent will be null to signify this is the root
FileSystem::FileSystem()
{
	root = std::make_shared<Directory>("Root", path, nullptr); 
	currentDirectory = root;     
}

FileSystem::~FileSystem() {}

std::shared_ptr<Directory> FileSystem::getRoot() 
{
	return root; 
}

std::shared_ptr<Directory> FileSystem::getCurrentDirectory() 
{
	return currentDirectory; 
}

//move to a specific path
bool FileSystem::moveTo(Path& path)
{
	if (path.getPart(ROOT) != ROOT_STR) //the path does not start with "Root" 
		return false; //the path is not valid

	std::shared_ptr<Directory> newDirectory = findDirectory(path, root, START);    
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
	for (std::shared_ptr<Directory> child : currentDirectory->getDirectories())  
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

//returns all files with the given name
std::vector<std::shared_ptr<File>> FileSystem::searchFile(const std::string name) 
{
	return fileMap.getFiles(name); 
}

////returns the file at the given path
//std::shared_ptr<File> FileSystem::searchFile(Path& path)   
//{
//	std::shared_ptr<Directory> directory = findDirectory(path, root, START);     
//	if (directory != nullptr)
//	{
//		std::string fileName = path.getPart(path.getPartsCount() - 1); 
//		return directory->searchFile(fileName);  
//	}
//	return nullptr; 
//}

////creates a file with the given name and content
//bool FileSystem::createFile(const std::string& name, const std::string& content)
//{
//	std::shared_ptr<File> file = std::make_shared<File>(name, content, currentDirectory); 
//	return fileMap.addFile(file); 
//}



