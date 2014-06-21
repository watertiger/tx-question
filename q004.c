/**
 * @file q004.c
 * @brief none.
 * @author watertiger <darkwkt@gmail.com>
 * @date 2014-06-21
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 20

typedef unsigned long long u64;
typedef unsigned int u32;

/**
 * @brief max_palindrome  - 找出最大的有由两个个三位数乘积构成的回文数.
 * @param n 待判断的数
 * @return 1 是回文数，
 *	   0 不是回文数
 *
 */
int
is_palidrome( u32 n )
{
	char string[LEN];
	u32 i = 0;
	u32 len = 0;

	for ( i = 0; i < LEN; i++)
		string[i] = '\0';
	//itoa( n, string, 10);
	sprintf(string, "%u", n);
	len = strlen( string );
	for ( i = 0; i < len-i-1; i++)
		if ( string[i] != string[len-1-i])
			return 0;
	
	return 1;
}
/**
 * @brief max_palindrome  - 找出最大的有由两个个三位数乘积构成的回文数.
 * @return 返回最大的回文数.
 *
 * 上限：999*999 = 998001
 * 范围：[100,999]
 */
u32 max_palidrome (u32 low, u32 high)
{
	u32 max_pa = 0;
	u32 tmp_pa = 0;
	u32 i = high;
	u32 j = high;
	
	for (; i >= low; i--) {
		for( j = i ; j >= low; j--) {
			tmp_pa = i * j;
			//printf("%u * %u = %u\n", i, j, tmp_pa);
			if( is_palidrome( tmp_pa ) && (tmp_pa > max_pa) )
					max_pa = tmp_pa;
		}
		//i--;
	}

	return max_pa;
}

int
main ()
{
	u32 sum_ret = 0;
	
	sum_ret = max_palidrome(100, 999);	//993 * 913 = 906609
	printf("The result is %u.\n", sum_ret);
	
	return 0;
}