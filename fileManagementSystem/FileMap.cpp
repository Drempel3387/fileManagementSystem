#include "FileMap.h"
#include <iostream>
//constructors
FileMap::FileMap()
{
	fileMap = std::unordered_map<std::string, std::vector<std::shared_ptr<File>>>(); //maps file names to a vector of files with that name
}
FileMap::~FileMap() {} //destructor

//add a file to the map
void FileMap::addFile(std::shared_ptr<File> file) 
{
	std::string name = file->getName(); //get the name of the file
	std::vector<std::shared_ptr<File>> files = getFiles(name); //get the files with the same name as the file
	files.push_back(file); //add the file to the vector
	fileMap[name] = files; //add the vector to the map 
}

//remove a file from the map
void FileMap::removeFile(std::shared_ptr<File> file)
{
	std::string name = file->getName(); //get the name of the file
	std::vector<std::shared_ptr<File>> files = getFiles(name); //get the files with the same name as the file
	files.erase(std::remove(files.begin(), files.end(), file)); //remove the file from the vector
	fileMap[name] = files; //add the vector to the map 
}

//remove all files with the given name from the map
void FileMap::removeFile(const std::string& name)
{
	fileMap.erase(name); //remove the file from the map
}

//check if the map contains a file
bool FileMap::contains(std::shared_ptr<File> file) 
{ 
	return !(fileMap[file->getName()]).empty(); //check if the map contains a vector with the same name as the file   
}

//get the files with the same name as the file
std::vector<std::shared_ptr<File>> FileMap::getFiles(const std::string& name) 
{
	return fileMap[name]; //return the vector with the same name as the file 
}

//clear the map
void FileMap::clear()
{
	fileMap.clear(); //clear the map
}

//get the names of the files in the map
std::vector<std::string> FileMap::getNames()
{
	std::vector<std::string> names; //create a vector of strings to store the names of the files
	for (auto const& pair : fileMap) //for each pair in the map
		names.push_back(pair.first); //add the name of the file to the vector 
	return names; //return the vector 
}

//get the number of files in the map
size_t FileMap::getFileCount()
{
	size_t count = 0; //create a variable to store the number of files
	for (auto const& pair : fileMap) //for each pair in the map
		count += pair.second.size(); //add the number of files with the same name as the file to the count
	return count; //return the count
}
