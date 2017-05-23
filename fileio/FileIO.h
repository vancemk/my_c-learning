#pragma once
#include <vector>
#include <string>

#ifndef FILEIO_H_

#define FILEIO_H_

namespace nFILEIO
{
	class FileIO
	{	
	public:
		char* ReadFile_once(const char* pFilePath_In);
		char* ReadFile_once1(const char* pFilePath_In);
		char* ReadFile_BySize1(const char* pFilePath_In, int nStartPos_In, int nSizeRead_In);
		void ReadFile_ByLine1(const char* pFilePath_In, std::vector < const char*>& colLines_out);

	};
}

#endif // !CLASSIO_H_