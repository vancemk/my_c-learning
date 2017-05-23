
#include "FileIO.h"
#include <fstream>
#include <iostream>
#include <string>


using namespace nFILEIO;
using namespace std;

char* FileIO::ReadFile_once(const char* pFilePath_In) {
	std::ifstream t(pFilePath_In);
	std::string strbuffer((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
	char* pData_Out = (char*)strbuffer.c_str();
	cout << "*pData_Out: " << *pData_Out << endl << endl << "&pData_Out: " << &pData_Out << endl << endl << "pData_Out: " << pData_Out << endl;
	std::cout << endl << strlen(pData_Out) << ":" << pData_Out[26] << pData_Out[25] << endl;
	t.close();
	return pData_Out;
}

char* FileIO::ReadFile_once1(const char* pFilePath_In) {
	std::ifstream t(pFilePath_In);
	std::string strbuffer((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
	int n = strbuffer.length();
	char *pData_Out = new char[n + 1];
	pData_Out[n] = '\0';
	while (n-- > 0)
		pData_Out[n] = strbuffer[n];
	cout << "*pData_Out: " << *pData_Out << endl << endl << "&pData_Out: " << &pData_Out << endl << endl << "pData_Out: " << pData_Out << endl;
	std::cout << endl << strlen(pData_Out) << ":" << pData_Out[26] << pData_Out[25] << endl;
	t.close();
	return pData_Out;
}


char* FileIO::ReadFile_BySize1(const char* pFilePath_In, int nStartPos_In, int nSizeRead_In)
{
	std::ifstream t(pFilePath_In);
	std::string strbuffer((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());

	string temp = strbuffer.substr(nStartPos_In, nSizeRead_In);
	//char* pData_out = (char*)temp.c_str();
	int n = nSizeRead_In;
	char* pData_Out = new char[n + 1];

	pData_Out[nSizeRead_In] = '\0';
	while (n-- > 0)
		pData_Out[n] = temp[n];
	//cout << pData_Out << endl;

	t.close();
	return pData_Out;
}

void FileIO::ReadFile_ByLine1(const char* pFilePath_In, std::vector < const char*> &colLines_out) {
	//vector<const char*> colLines_out;
	ifstream in(pFilePath_In);
	string filename;
	string line;
	if (in) // 有该文件  
	{
		while (getline(in, line)) // line中不包括每行的换行符  
		{

			int len = line.length();
			//cout << line << endl;
			char * pData_out = new char[len + 1];
			pData_out[len] = '\0';
			while (len--)
				pData_out[len] = line[len];

			colLines_out.push_back(pData_out);
			cout << "PDATAOUT " << &pData_out << endl;
			//delete[] pData_out;
			//cout << line << endl;
		}
	}
	in.close();

}