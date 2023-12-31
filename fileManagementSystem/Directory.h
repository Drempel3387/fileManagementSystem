#pragma once
#include <string>
#include <vector>
#include <memory>

#include "Path.h"
#include "File.h"

//this class will represent a directory in the file system
//it will contain a vector of files and a vector of directories
//it will also contain a name	
//it will provide methods to add and remove files and directories

/*important to note that nested directories are allowed to have the same name as a parent 
* the differentiating factor is the path
* for example, if we could have a directory called "test" in the root directory, a directory called "test" is allowed in the "test" directory
*/

class Directory
{
	private:
		//data members
		std::string name;//name of the directory
		Path path;//path of the directory

		std::vector<std::shared_ptr<File>> files;//vector of all files in the directory 
		std::vector<std::shared_ptr<Directory>> directories;//vector of all directories in the directory
		std::shared_ptr<Directory> parent;//pointer to the parent directory of the directory 

	public:
		//constructors and destructor
		Directory(const std::string&, const Path&, std::shared_ptr<Directory>); 
		Directory(const std::string&);
		Directory();
		~Directory();

		//getters
		Path getPath() const; 
		std::string getName() const;
		std::vector<std::shared_ptr<File>> getFiles() const; 
		std::vector<std::shared_ptr<Directory>> getDirectories() const; 
		std::shared_ptr<Directory> getParent() const;  

		//setters
		void setName(const std::string&);
		void setPath(const Path&);   
		
		//add methods + remove methods
		bool addFile(const std::shared_ptr<File>); //adds a file to the directory 
		bool addDirectory(const std::shared_ptr<Directory>); //adds a directory to the directory  
		bool removeFile(const std::shared_ptr<File>); //removes a file from the directory
		bool removeDirectory(const std::shared_ptr<Directory>); //removes a directory from the directory  

		//search methods
		std::shared_ptr<File> searchFile(const std::string&); //searches for a file in the directory by name 
		std::shared_ptr<Directory> searchDirectory(const std::string&); //searches for a directory in the directory by name

		//print methods
		void printFiles() const; //prints all files in the directory
		void printDirectories() const; //prints all directories in the directory

		//overloads
		bool operator==(const Directory&) const; //checks if two directories are equal
};

