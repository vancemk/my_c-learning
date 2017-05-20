#include <stdio.h>
#include <stdint.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include "base64.h"
#define DELTA 0x9e3779b9
#define MX (((z>>5^y<<2) + (y>>3^z<<4)) ^ ((sum^y) + (key[(p&3)^e] ^ z)))

void btea(uint32_t *v, int n, uint32_t const key[4]) {
	uint32_t y, z, sum;
	unsigned  rounds,p, e;

	//int p;
	if (n > 1) {          /* Coding Part */
		rounds = 6 + 52 / n;
		sum = 0;
		z = v[n - 1];
		do {
			sum += DELTA;
			e = (sum >> 2) & 3;
			for (p = 0; p< (n - 1); p++) {
				y = v[p + 1];
				z = v[p] += MX;
			}
			y = v[0];
			z = v[n - 1] += MX;
		} while (--rounds);
	}
	else if (n < -1) {  /* Decoding Part */
		n = -n;
		rounds = 6 + 52 / n;
		sum = rounds*DELTA;
		y = v[0];
		do {
			e = (sum >> 2) & 3;
			for (p = n - 1; p>0; p--) {
				z = v[p - 1];
				y = v[p] -= MX;
			}
			z = v[n - 1];
			y = v[0] -= MX;
			sum -= DELTA;
		} while (--rounds);
	}
}




//void btea(uint32_t *v,unsigned int n, uint32_t const key[4]); /* ... */

int main(void) {

	//std::cout << "read: " << pathname << std::endl;
	//char * c_pathname = (char *)pathname.c_str();
	//std::ifstream t("D:\\desk\\1.m4a", std::ios::binary);
	std::ifstream t("D:\\desk\\1.txt", std::ios::binary);

	//读取文件  
	//std::ifstream t("D:\\document\\1.jpg", std::ios::binary);	
	std::string s((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());

	//转换为 c风格字符串 
	std::string encoded = base64_encode(reinterpret_cast<const unsigned char*>(s.c_str()), s.length());   // 转为 base64 格式 
	//std::string encoded = base64_decode(s);
	char * srcBuffer = (char *)encoded.c_str();
	//std::cout << "encoded: " << srcBuffer << std::endl << std::endl << std::endl << std::endl;
	

	//uint32_t u_srcBuffer = convert_thirty(s);

	uint32_t key[4] = { 1,2,3,4 };

	
	//int n = 128 / sizeof(uint32_t);
	//int n = strlen(srcBuffer)/ sizeof(uint32_t);
	int n = strlen(srcBuffer);// sizeof(uint32_t);
	std::cout << strlen(srcBuffer) << std::endl;
	std::cout << n << std::endl;
	

	//printf("%s\n", u_srcBuffer);
	btea((uint32_t*)srcBuffer, n, key);
	//printf("encode: %s\n", srcBuffer);
	std::cout << "len of srcBuffer: " << strlen(srcBuffer) << std::endl;
/*
	n = strlen(srcBuffer) / sizeof(uint32_t);
	btea((uint32_t*)srcBuffer, -n, key);
	//std::cout << u_srcBuffer << std::endl;
	//printf("decode: %s\n", srcBuffer);

*/	
	std::ofstream outfile;
	outfile.open("3.m4a", std::ios::binary);
	outfile << srcBuffer;
	//delete srcBuffer;


	std::cin.get();
}

/*
char s[128] = "hello world bla bla bla bla bla bla";
uint32_t key[4] = { 1,2,3,4 };

int n = 128 / sizeof(uint32_t);

printf("%s\n", s);
btea((uint32_t*)s, n, key);
printf("%s\n", s);
btea((uint32_t*)s, -n, key);
printf("%s\n", s);
*/
