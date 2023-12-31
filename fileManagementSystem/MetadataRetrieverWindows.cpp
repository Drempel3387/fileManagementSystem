#include "MetadataRetrieverWindows.h"

//constructor
MetadataRetrieverWindows::MetadataRetrieverWindows(const Path& path)
{
	this->path = path;
}

//overrides
std::string MetadataRetrieverWindows::getCreationDateTime()
{
	//
	std::string creationDate;
	HANDLE hFile;
	FILETIME ftCreate, ftAccess, ftWrite;
	SYSTEMTIME stUTC, stLocal;

	// Convert the std::string path to LPCWSTR
	std::string pathStr = path.getPath(); 
	std::wstring wstrPath(pathStr.begin(), pathStr.end()); 
	LPCWSTR filePath = wstrPath.c_str(); 

	hFile = CreateFile(filePath, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL); 
	if (hFile != INVALID_HANDLE_VALUE)
	{
		if (GetFileTime(hFile, &ftCreate, &ftAccess, &ftWrite))
		{
			FileTimeToSystemTime(&ftCreate, &stUTC);
			SystemTimeToTzSpecificLocalTime(NULL, &stUTC, &stLocal);
			creationDate = std::to_string(stLocal.wDay) + "/" + std::to_string(stLocal.wMonth) + "/" + std::to_string(stLocal.wYear) 
				+ " " + std::to_string(stLocal.wHour) + ":" + std::to_string(stLocal.wMinute) + ":" + std::to_string(stLocal.wSecond); 
		}
	}
	CloseHandle(hFile);
	return creationDate;
}

size_t MetadataRetrieverWindows::getFileSize() {
	size_t fileSize = 0;
	HANDLE hFile;

	// Convert the std::string path to LPCWSTR
	std::string pathStr = path.getPath();	
	std::wstring wstrPath(pathStr.begin(), pathStr.end()); 
	LPCWSTR filePath = wstrPath.c_str();

	hFile = CreateFile(filePath, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile != INVALID_HANDLE_VALUE) {
		DWORD highSize = 0;//high part of the file size
		DWORD lowSize = GetFileSize(hFile, &highSize);//low part of the file size
		fileSize = ((size_t)highSize << 32) | lowSize;//combine the high and low parts of the file size
		CloseHandle(hFile);
	}
	return fileSize;
} 