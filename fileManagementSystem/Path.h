#pragma once
#include <string>
#include <vector>

class Path
{
private:
	//data members
	std::string path;
	std::vector <std::string> pathParts; //will contain the parts of the path 
	std::string delimiter;

	//private methods
	void setPathParts();
	void pathPartsToPath();  //converts the pathParts vector to a string path
public:
	//constructors
	Path(const std::string&);
	Path();

	//getters
	std::string getPath() const;
	std::string getPart(size_t index) const;
	size_t getPartsCount() const;

	//setters
	void setPath(const std::string&);
	bool setPart(size_t index, const std::string& part);

	//overloads
	bool operator==(const Path& other) const;
};

