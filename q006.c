/**
 * @file q006.c
 * @brief none.
 * @author watertiger <darkwkt@gmail.com>
 * @date 2014-06-21
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef unsigned long long u64;

/**
 * @brief difference - 求平方和与和平方的差.
 * @param n 上限n
 * @return 差
 *
 * 前十个自然数的平方和是：
 * 12 + 22 + ... + 102 = 385
 * 前十个自然数的和的平方是：
 * (1 + 2 + ... + 10)2 = 552 = 3025
 * 所以平方和与和的平方的差是3025 - 385 = 2640.
 * 找出前一百个自然数的平方和与和平方的差。
 */
u64 difference ( u64 n)
{
	u64 i = 0, j = 0;
	u64 sqsum = 0;
	u64 sumsq = 0;
	
	for ( i = 1; i <= n; i++ ) {
		sqsum += i * i;
		sumsq += i;
	}
	sumsq *= sumsq;
	
	return sumsq - sqsum;
}

int
main ()
{
	u64 sum_ret = 0;
	sum_ret = difference(100);	//25164150
	printf("The result is %llu.\n", sum_ret);
	
	return 0;
}