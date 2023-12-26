#pragma once
#include <string>
#include <vector>
#include "Directory.h"

//this class will represent the file system
//it will contain a root directory	
//it will provide methods to add and remove files and directories
//it will provide methods to search for files and directories
//it will provide methods to move between directories

class FileSystem
{
	private:
		Directory root;
		Directory currentDirectory;
		const std::string rootName = "Root";
	public:
		//constructor and destructor
		FileSystem();
		~FileSystem();

		//search methods
		Directory searchDirectory(std::string directoryName); //searches the current directory for a directory
		File searchFile(std::string fileName); //searches the current directory	for a file

		//add methods
		void addDirectory(std::string name, Directory location); //adds a directory to the current directory
		void addFile(File file, Directory location); //adds a file to the current directory

		//remove methods
		void removeDirectory(std::string name); //removes a directory from the current directory
		void removeFile(std::string name); //removes a file from the current directory 

		//move methods
		void changeDirectory(std::string name); //change to a directory in the current directory

		//getters
		Directory getRoot();
		Directory getCurrentDirectory(); //returns the current directory 
};

