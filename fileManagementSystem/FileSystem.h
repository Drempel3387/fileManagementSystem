#pragma once
#include <string>
#include <vector>
#include "Directory.h"

//this class will represent the file system
//it will contain a root directory and the current directory
//it will contain methods to move around the file system

class FileSystem
{
	private:
		//variables
		Directory* root;
		Directory* currentDirectory;

		//constants
		const Path path = Path("Root");
		const int ROOT = 0;
		const int START = 1;
		const std::string EMPTY = "";

		Directory* findDirectory(Path& path, Directory& currentDirectory, int count); 

	public:
		//constructor and destructor
		FileSystem();
		~FileSystem();

		//move methods
		bool moveTo(Path& path); //move to a specific path 
		bool moveTo(const std::string name); //move into a child directory   
		bool moveBack(); //move back to the parent directory 

		//getters
		Directory* getRoot(); //returns the root directory
		Directory* getCurrentDirectory(); //returns the current directory  
};

