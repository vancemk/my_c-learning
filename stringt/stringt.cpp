
#include <cstring>

#include "stringt.h"

stringt::stringt(){       //default constructor
	int len = 4;
	ch = new char[4];
	strcpy_s(ch,4, "C++");
	std::cout << ch << " stringt has been created: " << std::endl;

}

stringt::stringt(const char* str) {
	int len = std::strlen(str);
	ch = new char[len + 11];
	//strcpy_s(ch, str);
	strcpy_s(ch,len+1, str);
	std::cout << "one argument created: " << ch << std::endl;

}

stringt::stringt(const stringt& st) {          // 没有复制构造函数的时候将使用 浅复制
	int len = strlen(st.ch);
	ch = new char[len + 1];
	strcpy_s(ch, len + 1, st.ch);
	std::cout << "copy constructor has created: " << std::endl;
}

std::ostream & operator<<(std::ostream&os, const stringt& st) {
	os << st.ch ;
	return os;
}



stringt& stringt::operator=(stringt& st) {
	if (this == &st)                       // 比较的是地址
		return *this;
	int len = strlen(st.ch);
	delete [] ch;                          // 重新分配地址
	//delete ch;
	ch = new char[len + 1];
	strcpy_s(ch, len + 1, st.ch);
	std::cout << "copy success" << std::endl;
	return *this;
}

stringt& stringt::operator=(char* str) {
	delete[] ch;
	int len = strlen(str);
	ch = new char[len+1];
	strcpy_s(ch, len + 1, str);
	std::cout << "overload = char*str" << std::endl;
	return *this;
}


stringt operator+(const stringt& st1, const stringt& st2) {
	stringt temp1;
	delete [] temp1.ch;
	int n = strlen(st1.ch);
	int m = strlen(st2.ch);
	temp1.ch = new char[n + 1 ];
	strcpy_s(temp1.ch, n+1, st1.ch);
	strcat_s(temp1.ch, n + m + 1, st2.ch);
	return temp1;
}



bool operator == (const stringt& str1, const stringt& str2) {
	if (strcmp(str1.ch, str2.ch) == 0)
	{
		return true;
	}
	return false;
}


stringt::~stringt(){}



/*stringt& stringt::operator+(stringt& st) {
if (this == &st) {
stringt temp = *this;
std::cout << strlen(temp.ch) << std::endl;
std::cout << "temp.ch: " << temp.ch <<"  " << &temp << " lct: t "
<<  this << std::endl << "this.ch::: " << this->ch << std::endl;
//delete[] this->ch;
//this->ch = new char[11];
std::cout << "temp.ch: " << temp.ch << "  " << &temp << " lct: t "
<< this << std::endl << "this.ch" << this->ch << std::endl;
std::cout << "this->ch " << strlen(this->ch) << " strlen(temp.ch) " << strlen(temp.ch) << std::endl;

strcat_s(this->ch, 11, temp.ch);

std::cout << "字符串不能与自己相加" << std::endl;
return *this;
}
else {
int len = strlen(this->ch) + strlen(st.ch);
std::cout << "biaoji: " << len << std::endl;
strcat_s(this->ch, len + 9, st.ch);
//strncat(this->ch, st.ch,len + 1);
return *this;
}
}*/