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
		std::string path;
		std::vector<File> files;
		std::vector<Directory> directories;
	public:
		//constructor and destructor
		Directory(const std::string name);
		Directory();
		~Directory();

		//getters
		std::string getPath() const;
		std::string getName() const;
		std::vector<File> getFiles() const;
		std::vector<Directory> getDirectories() const;

		//setters
		void setFiles(const std::vector<File> files);
		void setName(const std::string name);
		void setPath(const std::string path);
		void setDirectories(const std::vector<Directory> directories);
		
		//add methods + remove methods
		bool addFile(const File file); //adds a file to the directory
		bool addDirectory(const Directory directory); //adds a directory to the directory
		bool removeFile(const File file); //removes a file from the directory
		bool removeDirectory(const Directory directory); //removes a directory from the directory

		//search methods
		File* searchFile(const std::string name); //searches for a file in the directory by name
		Directory searchDirectory(const std::string name) const; //searches for a directory in the directory

};

