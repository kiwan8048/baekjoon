/*
1. DP 틀 짜기
2. 출력
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 1024

int dp[MAX];

int solve(int n)
{
	int i;
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2; 
	dp[3] = 4; 
	for (i = 4; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
	return dp[n];
}


int main(void)
{
	int i, num, n, result;
	scanf("%d", &num);
	for (i = 0; i < num; i++)
	{
		scanf("%d", &n);
		result = solve(n);
		printf("%d\n", result);
	}
	return 0;
}