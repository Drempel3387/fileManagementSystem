#pragma once
#include <string>
#include <vector>
#include "Directory.h"

//this class will represent the file system
//it will contain a root directory and the current directory
//it will contain methods to move around the file system
//

class FileSystem
{
	private:
		//variables
		Directory root;
		Directory currentDirectory;

		//constants
		const std::string rootName = "Root";
		const std::string path = "Root";
		const std::string EMPTY = "";

	public:
		//constructor and destructor
		FileSystem();
		~FileSystem();

		//move methods
		bool moveTo(const std::string path); //move to a specific path
		void moveBack(); //move back to the parent directory
		void moveInto(const std::string name); //move into a child directory 

		//getters
		Directory getRoot();
		Directory getCurrentDirectory(); //returns the current directory 
};

