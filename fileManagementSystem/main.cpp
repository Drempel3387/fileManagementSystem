#include <iostream>
#include <fstream>
#include <string>
#include "MetadataRetrieverUnix.h"
#include "MetadataRetrieverWindows.h"
#include "Directory.h"
#include "Path.h"
#include "FileSystem.h"
#include "FileMap.h"

int main(void)
{
	Path path("C:\\Users\\Devon\\source\\repos\\fileManagementSystem\\fileManagementSystem\\test.txt");
	std::shared_ptr<MetadataRetrieverWindows> retriever = std::make_shared<MetadataRetrieverWindows>(path); 
	Metadata metadata(path, std::move(retriever));   

	std::cout << metadata.getCreationDate() << std::endl; 
	return 0;
}