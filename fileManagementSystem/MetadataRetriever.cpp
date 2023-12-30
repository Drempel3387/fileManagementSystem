#include "MetadataRetriever.h"

MetadataRetriever::MetadataRetriever(const Path& path)
{
	this->path = path;
}

Path MetadataRetriever::getPath() const
{
	return this->path;
}

void MetadataRetriever::setPath(const Path& path)
{
	this->path = path;
} 


