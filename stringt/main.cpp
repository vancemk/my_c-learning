
#include "stringt.h"
#include <cstring>
#include <string>

//using std::cout;
//using std::endl;

int main() {


	/*char bb[20] = "ygkk";
	cout << bb;
	char cc[5] = "kved";
	strcat_s(bb, 9, cc);
	cout << bb << endl;
	*/
/*	
	std::string aa = "kkkkkkkllllll";
	std::cout << aa+aa;
	stringt a;
	char c[10] = "hello";
	std::cout << std::strlen(c);
	stringt b("hello");
	std::cout << b << std::endl << a;
	*/

	stringt aa("hello");
	stringt bb("world");
	stringt cc = aa + bb;
	std::cout << cc ;
	/*
	stringt b = "abcde";
	stringt l("opqrs");
	std::cout << b << std::endl;
	stringt d = b + b;
	cout << "b + b: " << d << endl;
	std::cout << "b  " << b << endl;
	stringt p = l + b;
	cout << "p = a + b: " << p << endl;
	*/



	return 0;
}