#include <cstring>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	char * cstring1 = "hello, world!";
	char cstring2[10] = "hi, Cplus";
	//char cstring2[1] = "G";        invalid：  c风格字符串是 const 类型
	char cstring3[] = "goodwith";


	cout << cstring1 << " : " << &cstring2 << " : " << strlen(cstring1) << endl
		 << cstring2 << " : " << strlen(cstring2) << endl
		 << cstring3 << " : " << strlen(cstring3) << endl << endl;
	cout << cstring1[1] << endl << endl;
	while (*cstring1)                 // cstring1 指向的对象发生变化
	{
		cout << *cstring1 << endl;
		cstring1++;
	}

	/*string string1("dcd_");  // invalid: string越界
	cstring4[5] = cstring1[7];*/ 
	
	cout << &cstring2 << endl;
	string string2 = cstring2;
	cout << string2 << endl;
	string2.insert(0, "dcd_");
	cout << string2 << endl << endl;

	char * cstring4 = (char*)string2.c_str();  
	cout << cstring4 << endl;

	/*string string3 = "string3";      // 报错： const char* 值不能用于初始化 char*
	char* cstring5 = string3.c_str();*/

	return 0;
}