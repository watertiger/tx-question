/**
 * @file q005.c
 * @brief none.
 * @author watertiger <darkwkt@gmail.com>
 * @date 2014-06-21
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef unsigned long long u64;

/**
 * @brief least_common_multiple - 求连续n个数的最小公倍数.
 * @param n 上限n
 * @return 最小公倍数
 *
 * 找出最小的能被1-20中每个数整除的数。
 * 2520是最小的能被1-10中每个数字整除的正整数。
 * 最小的能被1-20中每个数整除的正整数是多少？
 * lcm = 2^4 * 3^2 * 5 * 7 * 9 * 11 * 13 * 17 * 19.
 *
 */
u64 least_common_multiple ( u64 n)
{
	u64 i = 0, j = 0;
	u64 mulsum = 1;
	u64 lcm = 1;
	
	for ( i = 2; i <= n; i++ ) {
		if ( lcm % i) { //如果lcm能整除i，则无需任何操作
			for ( j = i; j*i <= n;) {
				j *= i;
			}
			lcm *= j;
		}
	}
	
	return lcm;
}

int
main ()
{
	u64 sum_ret = 0;
//	u64 lcm = 16 * 9 * 5 * 7 * 11 * 13 * 17 * 19;	//232792560
//	printf("The result is %llu.\n", lcm);
	sum_ret = least_common_multiple(20);	//232792560
	printf("The result is %llu.\n", sum_ret);
	
	return 0;
}