#include "Path.h"

//constructors
Path::Path(const std::string path): path(path) {}
Path::Path() : path("") {}
Path::Path(const Path& other) : path(other.path) {}

//getters
std::string Path::getPath() const
{
	return path;
}

//setters
void Path::setPath(const std::string path)
{
	this->path = path;
}

bool Path::operator==(const Path& other) const
{
	return this->path == other.path;
}

//will remove common portions of two paths
//for example, if path1 is /home/user1 and path2 is /home/user1/test, the result will be /test

Path& Path::operator-(const Path& other)
{
	//if the paths are equal, set the path to an empty string
	if (*this == other)
	{
		this->path = "";
		return *this;
	}

	//if the other path is longer than this path, return
	if (other.path.length() > this->path.length())
	{
		return *this;
	}

	//if the other path is not a substring of this path, return
	if (this->path.find(other.path) == std::string::npos)
	{
		return *this;
	}

	//if the other path is a substring of this path, remove the substring from this path
	this->path = this->path.substr(other.path.length(), this->path.length() - other.path.length());
	return *this;
}

