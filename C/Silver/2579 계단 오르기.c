/*
1. dp 이용
2. 출력
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int total[10001];

int max(int a, int b)
{
	return ((a > b) ? a : b);
}

int dp(int n, int point[])
{
	int i;
	total[0] = 0;
	total[1] = point[0];
	total[2] = point[0] + point[1];
	for (i = 3; i <= n; i++)
	{
		total[i] = max(total[i - 2], total[i - 3] + point[i - 2]) + point[i - 1];
	};
	return total[n];
}



int main(void)
{
	int i, n, result;
	int point[301];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &point[i]);
	}
	result = dp(n, point);
	printf("%d", result);
	return 0;
}