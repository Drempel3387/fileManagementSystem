#pragma once
#include <string>
#include <vector>
#include "File.h"
//this class will represent a directory in the file system
//it will contain a vector of files and a vector of directories
//it will also contain a name	
//it will provide methods to add and remove files and directories

class Directory
{
	private:
		std::string name;
		std::vector<File> files;
		std::vector<Directory> directories;
	public:
		//constructor and destructor
		Directory(std::string name);
		Directory();
		~Directory();

		//getters
		std::string getName();
		std::vector<File> getFiles();
		std::vector<Directory> getDirectories();

		//setters
		void setFiles(std::vector<File> files);
		void setName(std::string name);
		void setDirectories(std::vector<Directory> directories);
		
		//add methods + remove methods
		bool addFile(File file); //adds a file to the directory
		void addDirectory(Directory directory); //adds a directory to the directory
		void removeFile(std::string name); //removes a file from the directory
		void removeDirectory(std::string name); //removes a directory from the directory

};

