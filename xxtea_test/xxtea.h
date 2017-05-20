#ifndef XXTEA_h
#define XXTEA_h

#include "stdlib.h"
#include "stdio.h"
#include <string.h>

#ifndef XXTEA_TYPE
#define XXTEA_TYPE int         // һ��32λ�����������ͣ���int��32bit��64bitϵͳ�ж���32λ�ģ���ֱ����int
#endif

class XXTEA {
public:
    XXTEA();
    ~XXTEA();
    
public:
    /**
     *    @brief     �������������ĳ���
     *
     *    @param     nLength     ���뻺��������
     *    @param     isEncode     TRUE ��Ϊ���ܣ�FALSE��Ϊ����
     *
     *    @return    �������賤��
     */
    static size_t XXTEAGetBufferLength(size_t nLength, bool isEncode);
    
    /**
     *    @brief    �����������м���
     *
     *    @param     lpDstBuffer     Ŀ�껺����
     *    @param     lpSrcBuffer     Դ������
     *    @param     nLength     Դ����������
     *    @param     lpKey     ��Կ 
     *
     *    @return    �����Ƿ�ɹ�
     */
    static bool XXTEAEncode(char* lpDstBuffer, const char* lpSrcBuffer, size_t nLength, const XXTEA_TYPE* lpKey);

    /**
     *    @brief    �����������н���
     *
     *    @param     lpDstBuffer     Ŀ�껺����
     *    @param     lpSrcBuffer     Դ������
     *    @param     nLength     Դ����������
     *    @param     lpKey     ��Կ
     *
     *    @return    �����Ƿ�ɹ�
     */
    static bool XXTEADecode(char* lpDstBuffer, const char* lpSrcBuffer, size_t nLength, const XXTEA_TYPE* lpKey);

private:
    /**
     *    @brief    XXTEA�ٷ��㷨�����༴�Ƕ�����з�װ�����http://en.wikipedia.org/wiki/XXTEA
     *
     *    @param     v     �ӽ���������
     *    @param     n     �ӽ��ܳ��ȣ�n > 1Ϊ���ܣ�n < -1Ϊ����
     *    @param     k     ��Կ      ע�⣺��ʽ����k���MX�е�k��Ӧ
     *
     *    @return    ����0��ʾ�ӽ��ܳɹ�������1��ʾʧ��
     */
    static long btea(XXTEA_TYPE* v, long n, const XXTEA_TYPE* k);

    /**
     *    @brief    �����ַ�����16���Ʊ���
     *
     *    @param     surBuffer     Դ������
     *    @param     length     Դ����������
     *    @param     dstBuffer     Ŀ�껺����
     */
    static void StringToHex(const char* surBuffer, int length, char* dstBuffer);

    /**
     *    @brief    16�����ַ��������������ַ���
     *
     *    @param     surBuffer     Դ������
     *    @param     dstBuffer     Ŀ�껺����
     *
     *    @return    Ŀ�껺�����ĳ���
     */
    static int HexToString(const char* surBuffer,  char* dstBuffer);
};

#endif
