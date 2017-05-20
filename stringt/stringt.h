#pragma once

#include <iostream>

#ifndef STRINGT_H_
#define STRINGT_H_
class stringt;

class stringt
{
private:
	int l;
	char *ch;
public:
	stringt();
	stringt(const char* str);
	stringt(const stringt& st);
	~stringt();
	friend std::ostream & operator<<(std::ostream&os, const stringt& st);
	stringt& operator=(stringt& st);
	stringt& operator=(char* str);
	friend bool operator == (const stringt& str1, const stringt& str2);
	friend stringt operator+(const stringt& st1, const stringt& st2);
	//stringt& operator+(stringt& st);  st+st 会改变 st 的值

};





#endif // !1

