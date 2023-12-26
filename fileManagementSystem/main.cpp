#include <iostream>
#include <string>
#include "File.h"
#include "Metadata.h"
int main(void)
{
	File file("test.txt", "2020-01-01 00:00:00", 100, "This is a test file.");
	std::cout << file << std::endl;	
	return 0;
}