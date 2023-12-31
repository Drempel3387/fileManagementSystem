#include <iostream>
#include <fstream>
#include <string>
#include "Directory.h"
#include "Path.h"

int main(void)
{
	Directory root = Directory("Root", Path("Root"), nullptr);
	File file = File(Path("C:\\Users\\Devon\\source\\repos\\fileManagementSystem\\fileManagementSystem\\test.txt"));

	return 0;
}