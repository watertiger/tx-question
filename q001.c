/**
 * @file q001.c
 * @brief none.
 * @author watertiger <darkwkt@gmail.com>
 * @date 2014-06-21
 */

#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long u64;

/**
 * @brief sum_of_times - 计算某两个因子的倍数和.
 * @param n 上限
 * @param a 因子a
 * @param b 因子b
 * @return 在范围[0,n)内 整除a或b的数之和.
 *
 * 例如，找出1000以下自然数中3和5的倍数之和。
 * 10以下的自然数中，属于3和5的倍数的有3,5,6和9，它们之和是23.
 * 找出1000以下的自然数中，属于3和5的倍数的数字之和。
 * 
 */
u64 sum_of_times ( u64 n, u64 a, u64 b)
{
	u64 i = 0;
	u64 sum = 0;
	u64 count;
	u64 div_ret = 0;
	
//	assert(a);
//	assert(b);
	
	div_ret = (n-1) / a;
	count = 0;
	for (i = 1; i <= div_ret; i ++) 
		count += i;
	sum += count * a;
	
	div_ret = (n-1) / b;
	count = 0;
	for (i = 1; i <= div_ret; i ++) 
		if ( i % a)
			count += i;
	sum += count * b;
	
	return sum;
}

int
main ()
{
	u64 sum_ret = 0;
	
	sum_ret = sum_of_times(1000, 3, 5);	//233168
	printf("The result is %llu.\n", sum_ret);
	
	return 0;
}