#include "Path.h"
#include <string>
Path::Path()
{
	path = "";
}
Path::Path(const std::string path)
{
	this->path = path;
}
std::string Path::getPath() const
{
	return path;
}
void Path::setPath(const std::string path)
{
	this->path = path;
}