#pragma once
#include <string>
class Path
{
private:
	std::string path;
public:
	Path();
	Path(const std::string path);
	std::string getPath() const;
	void setPath(const std::string path);
};

