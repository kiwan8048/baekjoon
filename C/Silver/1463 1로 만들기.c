/*
1. dp를 이용해 점화식 연산
2. 출력
*/

int table[100001];

int dp(int num)
{
	int i;
	table[1] = 0;
	for (i = 2; i <= num; i++)
	{
		table[i] = table[i - 1] + 1;
		if (i % 2 == 0) table[i] = (table[i / 2] + 1 < table[i]) ? table[i / 2] + 1 : table[i];
		if (i % 3 == 0) table[i] = (table[i / 3] + 1 < table[i]) ? table[i / 3] + 1 : table[i];
	}
	return table[num];
}



#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int num, result;
	scanf("%d", &num);
	result = dp(num);
	printf("%d", result);
	return 0;
}