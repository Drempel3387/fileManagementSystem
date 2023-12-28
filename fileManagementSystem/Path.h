#pragma once
#include <string>
#include <vector>

class Path
{
private:
	//data members
	std::string path;
	std::vector <std::string> pathParts; //will contain the parts of the path

	//private methods
	void setPathParts(); 
public:
	//constructors
	Path(const std::string&);
	Path();

	//getters
	std::string getPath() const;
	std::vector <std::string> getPathParts() const;

	//setters
	void setPath(const std::string&);

	//overloads
	bool operator==(const Path& other) const;
};

