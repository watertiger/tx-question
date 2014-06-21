/**
 * @file q003.c
 * @brief none.
 * @author watertiger <darkwkt@gmail.com>
 * @date 2014-06-21
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef unsigned long long u64;

/**
 * @brief is_prime - 判断一个数是否为质数.
 * @param n 待判断的数
 * @return 1 是质数，
 *	   0 不是质数
 *
 */
u64 is_prime ( u64 n)
{
	u64 i = 0;
	u64 root_sqrt = ( u64 ) sqrt(n);
	
	for ( i = 2; i <= root_sqrt; i++) {
		if ( 0 == (n % i) )
			return 0;
	}
	
	return 1;
}

/**
 * @brief max_prime_factor - 找出一个合数的最大质数因子.
 * @param n 待分解的数
 * @return 最大质数因子.
 *
 */
u64 max_prime_factor ( u64 n)
{
	u64 maxp = 0;
	u64 i = 0;
	u64 root_sqrt = 0;
	u64 quotient = 0;
/*方法1：	
	for ( i = 2; i < n; i++) {
		if ( 0 == (n%i) ) {
			if ( is_prime(i)) {
				maxp = i;
			}
		}
	}
*/
//方法2：	一次判断两个数
	root_sqrt = sqrt(n);
	for ( i = 2; i <= root_sqrt; i++) {
		if ( 0 == (n%i) ) {
			quotient = n / i;
			if ( is_prime(quotient)) {
				maxp = quotient;
				return maxp;
			}
			if ( is_prime(i)) {
				maxp = i;
			}
		}
	}	
	
	return maxp;
}

int
main ()
{
	u64 sum_ret = 0;
	
	sum_ret = max_prime_factor(600851475143);	//
	printf("The result is %llu.\n", sum_ret);
	
	return 0;
}