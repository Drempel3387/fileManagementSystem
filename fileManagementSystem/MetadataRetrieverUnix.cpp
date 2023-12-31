#ifdef _WIN32
#else

#include "MetadataRetrieverUnix.h"
//constructor
MetadataRetrieverUnix::MetadataRetrieverUnix(const Path& path)
{
	this->path = path;
}

//get the metadata of the file
struct stat MetadataRetrieverUnix::getFileStat(const Path& path)
{
	struct stat fileStat;
	if (stat(path.getPath().c_str(), &fileStat) == - 1) 
	{
		std::cout << "Error getting file stats" << std::endl;
	}
	return fileStat;
}

convert the time_t object to a string
std::string MetadataRetrieverUnix::convertTimeToString(const time_t& time)
{
	std::string timeString = ctime(&time); //convert the time_t object to a string  
	timeString.erase(timeString.length() - 1); //remove the newline character from the end of the string
	return timeString;
}

//get the creation date of the file
std::string MetadataRetrieverUnix::getCreationDateTime(const Path& path)
{
	struct stat fileStat = getFileStat(path);
	return convertTimeToString(fileStat.st_ctime);
}

//get the size of the file
size_t MetadataRetrieverUnix::getFileSize(const Path& path)
{
	struct stat fileStat = getFileStat(path);
	return fileStat.st_size;
}

#endif