#include "Path.h"

void Path::setPathParts()
{
	std::string part = ""; //will contain the current part of the path 
	size_t lastPart = 0; //will contain the index of the last part of the path
	size_t currentPart = 0; //will contain the index of the current part of the path

	if (path == "")//empty path, no parts
		return;

	while (currentPart != std::string::npos) //while we have not reached the end of the path
	{
		currentPart = path.find('/', lastPart); //find the next part of the path
		part = path.substr(lastPart, currentPart - lastPart); //get the part of the path

		if (part != "")
			pathParts.push_back(part); //add the part to the vector

		lastPart = currentPart + 1; //set the last part to the current part + 1
	}	
}

//constructors
Path::Path(const std::string& path): path(path) 
{
	setPathParts(); 
}
Path::Path() : path("") {}

//getters
std::string Path::getPath() const
{
	return path;
}

std::vector<std::string> Path::getPathParts() const
{
	return pathParts;
}

//setters
void Path::setPath(const std::string& path) 
{
	this->path = path;
}

bool Path::operator==(const Path& other) const
{
	return this->path == other.path;
}


