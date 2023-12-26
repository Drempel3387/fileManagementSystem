#include <iostream>
#include <fstream>
#include <string>
#include "File.h"
#include "Metadata.h"
int main(void)
{
	File file("test.txt", "2020-10-10 10:10:10", "Hello World!");
	std::cout << file << std::endl;
	return 0;
}