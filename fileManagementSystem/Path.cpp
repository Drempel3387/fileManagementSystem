#include "Path.h"
#include "DelimeterRetriever.h"

void Path::setPathParts()
{
	std::string part = ""; //will contain the current part of the path 
	size_t lastPart = 0; //will contain the index of the last part of the path
	size_t currentPart = 0; //will contain the index of the current part of the path

	if (path == "")//empty path, no parts
		return;

	while (currentPart != std::string::npos) //while we have not reached the end of the path
	{
		currentPart = path.find(delimiter, lastPart); //find the next part of the path 
		part = path.substr(lastPart, currentPart - lastPart); //get the part of the path

		if (part != "")
			pathParts.push_back(part); //add the part to the vector

		lastPart = currentPart + 1; //set the last part to the current part + 1
	}	
}

void Path::pathPartsToPath()
{
	std::string path = ""; //will contain the path
	for (const auto& part: pathParts)
		path += part + delimiter; //add the part and the delimiter to the path

	this->path = path;
}

//constructors
Path::Path(const std::string& path): path(path) 
{
	delimiter = DelimeterRetriever::getDelimeter(); 
	setPathParts(); 
}
Path::Path() : path("") {}

//getters
std::string Path::getPath() const
{
	return path;
}

std::string Path::getPart(size_t index) const
{
	return pathParts[index];
}

size_t Path::getPartsCount() const
{
	return pathParts.size(); 
}

//setters
void Path::setPath(const std::string& path) 
{
	this->path = path;
	setPathParts();
}

bool Path::setPart(size_t index, const std::string& part)
{
	if (index >= pathParts.size())
		return false;

	pathParts[index] = part; 
	pathPartsToPath();
	return true;
}

bool Path::operator==(const Path& other) const
{
	return this->path == other.path;
}


