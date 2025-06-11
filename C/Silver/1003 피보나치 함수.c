/* 
1. DP 구현
2. 출력
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int dp[1024][2];

void solve(int num)
{
	int i;
	dp[0][0] = 1;
	dp[0][1] = 0;
	dp[1][0] = 0;
	dp[1][1] = 1;	 
	for (i = 2; i <= num; i++)
	{
		dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
		dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
	}
	return;
}




int main(void)
{
	int i, n, num;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &num);
		solve(num);
		printf("%d %d\n", dp[num][0], dp[num][1]);
	}
	return 0;
}