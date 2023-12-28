#include <iostream>
#include <fstream>
#include <string>
#include "Directory.h"
#include "Path.h"
#include "FileSystem.h"


int main(void)
{
	FileSystem fileSystem; //create a file system
	Directory dir = Directory("test", Path("Root/test"), fileSystem.getRoot());    
	Directory dir2 = Directory("test2", Path("Root/test2"), &dir);     

	Path path = Path("Root/test");   
	Path path2 = Path("Root/test2");    
	fileSystem.getCurrentDirectory()->addDirectory(&dir); //add a directory to the root directory       
	fileSystem.getCurrentDirectory()->addDirectory(&dir2); //add a directory to the root directory    

	fileSystem.moveTo(path); //move to the directory with the path "Root/test" 
	std::cout << fileSystem.getCurrentDirectory()->getPath().getPath() << std::endl; //print the name of the current directory	

	file
	return 0;
}