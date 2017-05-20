//
//  XXTEA.cpp
//
//  Created by Yuming on 12-7-24.
//  Copyright (c) 2012å¹´ __MyCompanyName__. All rights reserved.
//

#include "XXTEA.h"
#define     MX      (z>>5^y<<2) + (y>>3^z<<4)^(sum^y) + (k[p&3^e]^z);
#define     XXTEA_ALIGNMENT_BYTES                 4
#include <vector>
#include <string>
#include<fstream>     
#include<io.h>   

XXTEA::XXTEA(){
    
}

XXTEA::~XXTEA(){
    
}

size_t XXTEA::XXTEAGetBufferLength(size_t nLength, bool isEncode){
    if (isEncode) {
        size_t nSize = nLength / XXTEA_ALIGNMENT_BYTES + (nLength % XXTEA_ALIGNMENT_BYTES  ? 1 : 0);
        return (nSize * XXTEA_ALIGNMENT_BYTES * 2 + 1);
    }
    else {
        return (nLength / 2 + 1);
    }
}

bool XXTEA::XXTEAEncode(char* lpDstBuffer, const char* lpSrcBuffer, size_t nLength, const XXTEA_TYPE* lpKey){
    long ret = 1;
    
    if (nLength > XXTEA_ALIGNMENT_BYTES && lpDstBuffer && lpSrcBuffer) {
        size_t nSize = nLength / XXTEA_ALIGNMENT_BYTES + (nLength % XXTEA_ALIGNMENT_BYTES  ? 1 : 0);
        char* data = (char*)malloc(nSize * XXTEA_ALIGNMENT_BYTES * 2);
        memset(data, 0, nSize * XXTEA_ALIGNMENT_BYTES * 2);
        memcpy(data, lpSrcBuffer, nLength);
        ret = btea((XXTEA_TYPE*)data, nSize, lpKey);
        
        memset(lpDstBuffer, 0, XXTEAGetBufferLength(nLength, true));
        StringToHex(data, (int)nSize * XXTEA_ALIGNMENT_BYTES, lpDstBuffer);
        free(data);
    }
    return (ret == 0);
}

bool XXTEA::XXTEADecode(char* lpDstBuffer, const char* lpSrcBuffer, size_t nLength, const XXTEA_TYPE* lpKey){
    long ret = 1;
    
    if (nLength > XXTEA_ALIGNMENT_BYTES * 2 && lpDstBuffer && lpSrcBuffer) {
        size_t nSize = XXTEAGetBufferLength(nLength, false);
        //printf("%d",ret);
        memset(lpDstBuffer, 0, nSize);
        //printf("%d\n",strlen(lpSrcBuffer));
        HexToString(lpSrcBuffer, lpDstBuffer);
        
        //HexToString(lpDstBuffer, lpSrcBuffer );
        
        ret = btea((XXTEA_TYPE*)lpDstBuffer, -((nSize - 1)/ XXTEA_ALIGNMENT_BYTES), lpKey);
        
    }
    return (ret == 0);
}

long XXTEA::btea(XXTEA_TYPE* v, long n, const XXTEA_TYPE* k) {
    unsigned XXTEA_TYPE z, y;
    unsigned long sum = 0, e, DELTA = 0x9e3779b9;
    long p, q;
    if (n > 1) {          /* Coding Part */
        z = v[n-1];
        q = 6 + 52 / n;
        while (q-- > 0) {
            sum += DELTA;
            e = (sum >> 2) & 3;
            for (p = 0; p < n-1; ++p) y = v[p+1], z = v[p] += MX;
            y = v[0];
            z = v[n-1] += MX;
        }
        return 0;
    } else if (n < -1) {  /* Decoding Part */
        y = v[0];
        n = -n;
        q = 6 + 52 / n;
        sum = q * DELTA ;
        while (sum != 0) {
            e = (sum >> 2) & 3;
            for (p = n-1; p > 0; --p) z = v[p-1], y = v[p] -= MX;
            z = v[n-1];
            y = v[0] -= MX;
            sum -= DELTA;
        }
        return 0;
    }
    return 1;
}

void XXTEA::StringToHex(const char* surBuffer, int length, char* dstBuffer){
    for (int i = 0; i < length; i++)
    {
        sprintf(&dstBuffer[2*i], "%02X", (unsigned char)surBuffer[i]);
    }
    dstBuffer[2 * length] = '\0';
}

int XXTEA::HexToString(const char* surBuffer,  char* dstBuffer){
    size_t length = strlen((char*)surBuffer) ;
    
    
    for(int i = 0; i < length/2; i++)
    {
        int temp;
        sscanf(&surBuffer[2 * i], "%02X", &temp);
        //printf("length %d\n", temp);
        dstBuffer[i] = (char)temp;
    }
    
    dstBuffer[length/2] = '\0';
    return (int)strlen((char*)dstBuffer);
}

void visit(std::vector <std::string> & vs, std::string path)     // ±éÀúÎÄ¼þ¼Ð 
{     
        struct _finddata_t   filefind;     
        std::string curr=path+"\\*.*";     
        int done=0,i,handle;   
	
        if((handle=_findfirst(curr.c_str(),&filefind))==-1)
			return;       
        while(!(done=_findnext(handle,&filefind)))     
        {   
			//cout << k++ << endl;      
 			if(!strcmp(filefind.name,"..")){  continue;  }   // Èç¹û×¢ÊÍÕâÒ»ÐÐ£¬»á³öÏÖºÜ¶àÑ­»· 
            if((_A_SUBDIR==filefind.attrib)) //ÊÇ ÎÄ¼þ¼Ð 
            	{             
    				    
                	//cout<<filefind.name<<"(dir)"<<endl;     
                	curr=path+"\\"+filefind.name; 
					visit(vs, curr);	
 				}
            else
 				{
				curr=path+"\\"+filefind.name;
 				if(curr.size()>2)
				{
				vs.push_back(curr); }
 
            	//cout << path + "\\"+filefind.name << endl;
            }
            	
        }             
        _findclose(handle);                 
}   


