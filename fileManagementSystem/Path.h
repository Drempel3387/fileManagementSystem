#pragma once
#include <string>

class Path
{
private:
	std::string path;

public:
	//constructors
	Path(const std::string);
	Path();
	Path(const Path&); //copy constructor

	//getters
	std::string getPath() const;

	//setters
	void setPath(const std::string);

	//overloads
	bool operator==(const Path& other) const;
	
	
	//will remove common portions of two paths
	//for example, if path1 is /home/user1 and path2 is /home/user1/test, the result will be /test
	Path& operator-(const Path& other);
};

