#include "FileIO.h"
#include <iostream>
#include <fstream>

using namespace nFILEIO;
using namespace std;


int main()
{
	FileIO temp;
	vector <const char*> v_colLines_out;
	temp.ReadFile_ByLine1("D:\\desk\\1.txt", v_colLines_out);
	int i ;
	for (i = 0; i < 5; i++)
		cout << v_colLines_out[i] << endl;

/*
	char* l = ReadFile_once1("D:\\desk\\1.txt");
	delete[] l;
	char* k = ReadFile_once("D:\\desk\\1.txt");
	
	char* m = ReadFile_BySize1("D:\\desk\\1.txt", 290, 200);
	delete m;
	cout << m << endl;
	delete [] m;
	*/
	cin.get();
	return 0;
}


