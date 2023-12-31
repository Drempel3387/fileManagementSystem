#include "MetadataRetriever.h"
#ifdef _WIN32
#include "MetadataRetrieverWindows.h"
#else
#include "MetadataRetrieverUnix.h"
#endif

//create a metadata retriever based on the OS
std::shared_ptr<MetadataRetriever> MetadataRetriever::create(const Path& path)
{
	#ifdef _WIN32
	return std::make_shared<MetadataRetrieverWindows>(path);
	#else
	return std::make_shared<MetadataRetrieverUnix>(path); 
	#endif // _WIN32
}

Path MetadataRetriever::getPath() const
{
	return this->path;
}

void MetadataRetriever::setPath(const Path& path)
{
	this->path = path;
} 


