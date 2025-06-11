/*
1. 전체 동전 입력 받기
2. 비용을 넘지 않는 가장 큰 동전 찾고 나눗셈으로 최대만큼 갖기, count 구매 수만큼 올리기
3. 비용을 가져온만큼 차감하기
4. 반복
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int i, n, cost, count = 0, save;
	int coin[11];
	scanf("%d %d", &n, &cost);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &coin[i]);
	}
	for (i = n - 1; i >= 0; i--)
	{
		if (coin[i] <= cost)
		{
			save = count;
			count += cost / coin[i];
			save = cost / coin[i];
			cost -= save * coin[i];
		}
	}
	printf("%d", count);
	return 0;
}
