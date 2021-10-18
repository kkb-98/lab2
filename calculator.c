#include <stdio.h>
#include "libtest.h"

int main()
{
	int n1, n2;
	printf("계산기 프로그램\n");
	printf("첫번째 숫자 : ");
	scanf("%d",&n1);
	printf("두번째 숫자 : ");
	scanf("%d",&n2);
	
	printf("%d + %d = %d\n", n1, n2, add(n1,n2));
	printf("%d - %d = %d\n", n1, n2, subtract(n1,n2));
	printf("%d * %d = %d\n", n1, n2, multiply(n1,n2));
	printf("%d / %d = %d\n", n1, n2, divide(n1,n2));
	
	printf("finish.\n");
	return 0;


}
