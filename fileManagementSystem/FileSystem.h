#pragma once
#include <string>
#include <vector>
#include "Directory.h"
#include "FileMap.h"

//this class will represent the file system
//it will provide the common interface for the user to interact with the file system 
//it will contain a root directory and the current directory
//it will contain methods to move around the file system
class FileSystem
{
	private:
		//variables
		std::shared_ptr<Directory> root; 
		std::shared_ptr<Directory> currentDirectory; 
		FileMap fileMap;

		//constants
		const Path path = Path("Root");
		const std::string ROOT_STR = "Root";
		const int ROOT = 0;
		const int START = 1;
		const std::string EMPTY = "";

		//private methods
		std::shared_ptr<Directory> findDirectory(Path& path, std::shared_ptr<Directory> currentDirectory, int count);  

	public:
		//constructor and destructor
		FileSystem();
		~FileSystem();

		//move methods
		bool moveTo(Path& path); //move to a specific path 
		bool moveTo(const std::string name); //move into a child directory   
		bool moveBack(); //move back to the parent directory 

		//search by file name methods
		std::vector<std::shared_ptr<File>> searchFile(const std::string name); //returns all files with the given name  
		std::shared_ptr<File> searchFile(Path& path); //returns the file at the given path   

		//search by directory name methods
		std::vector<Path> searchDirectory(const std::string name); //returns all directory paths with the given name

		//CRUD file methods
		bool createFile(const std::string& name, const std::string& content); //creates a file with the given name and content
		bool deleteFile(const std::string& name, const std::string& path = ""); //deletes the file with the given name and path
		

		//CRUD directory methods
		bool createDirectory(const std::string name, const std::string& path = ""); //creates a directory with the given name 
		bool deleteDirectory(const std::string name, const std::string& path = ""); //deletes the directory with the given name and path



		//getters
		std::shared_ptr<Directory> getRoot(); //returns the root directory 
		std::shared_ptr<Directory> getCurrentDirectory(); //returns the current directory  
}; 

