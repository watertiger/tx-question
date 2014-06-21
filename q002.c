/**
 * @file q002.c
 * @brief none.
 * @author watertiger <darkwkt@gmail.com>
 * @date 2014-06-21
 */

#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long u64;

/**
 * @brief sum_of_even - 计算斐波那契数列中偶数项的和.
 * @param n 上限
 * @return 在范围[0,n)内斐波那契数列中偶数项的和.
 *
 * 斐波那契数列中的每一项被定义为前两项之和。从1和2开始，斐波那契数列的前十项为：
 * 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
 * 考虑斐波那契数列中数值不超过4百万的项，找出这些项中值为偶数的项之和。
 *
 * 注意：由于每个偶数都是前面连续两个奇数之和，所以如果最后一个整数是偶数时，则
 * 结果为所有和的一半。（这里面，最开始三项为1,1,2以保持这一特性）
 */
u64 sum_of_even ( u64 n)
{
	u64 a1 = 1;
	u64 a2 = 0;
	u64 sum = 0;
	u64 i = 0;
	char counter3 = 2;

	
	for( i = 1; i < n; ) {
		a2 = a1 + i;
		counter3 ++;
		if (a2 > n)
			break;
		if (3 == counter3) {
			sum += a2;
			counter3 = 0;
		}
		a1 = i;
		i = a2;
	}
	
	return sum;
}

int
main ()
{
	u64 sum_ret = 0;
	
	sum_ret = sum_of_even(4000000);	//4613732
	printf("The result is %llu.\n", sum_ret);
	
	return 0;
}