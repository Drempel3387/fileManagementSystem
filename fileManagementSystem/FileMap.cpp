#include "FileMap.h"
#include <iostream>
//constructors
FileMap::FileMap(): std::unordered_map<std::string, std::vector<File*>>() {} //default constructor

FileMap::~FileMap() {} //destructor

//add a file to the map
void FileMap::addFile(File* file)
{
	std::string name = file->getMetadata().getName(); //get the name of the file
	std::vector<File*> files = getFiles(name); //get the files with the same name as the file
	files.push_back(file); //add the file to the vector
	(*this)[name] = files; //add the vector to the map
}

//remove a file from the map
void FileMap::removeFile(File* file)
{
	std::string name = file->getMetadata().getName(); //get the name of the file
	std::vector<File*> files = getFiles(name); //get the files with the same name as the file
	files.erase(std::remove(files.begin(), files.end(), file)); //remove the file from the vector
	(*this)[name] = files; //add the vector to the map
}

//check if the map contains a file
bool FileMap::contains(File* file)	
{ 
	return !((*this)[file->getMetadata().getName()]).empty(); //check if the map contains a vector with the same name as the file  
}

//get the files with the same name as the file
std::vector<File*> FileMap::getFiles(const std::string& name)
{
	return (*this)[name]; //return the vector with the same name as the file
}

//print the files in the map
void FileMap::printFiles()
{
	for (auto it = begin(); it != end(); ++it) //iterate through the map
	{
		std::cout << it->first << ": "; //print the name of the file
		for (auto it2 = it->second.begin(); it2 != it->second.end(); ++it2) //iterate through the vector
		{
			std::cout << (*it2)->getMetadata().getPath().getPath() << " "; //print the path of the file
		}
		std::cout << std::endl;
	}
}
