/*
1. 퀵정렬로 적은 시간 순으로 정렬
2. 첫 사용자가 걸리는 시간을 use_time으로 저장, total도 저장
3. 다음 사용자가 걸리는 기존 use_time에다가 더해서 저장하고, total에 use_time 더해서 저장
4. 출력
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}



int main(void)
{
	int person[1001];
	int i, num, use_time = 0, total = 0;
	scanf("%d", &num);
	for (i = 0; i < num; i++)
	{
		scanf("%d", &person[i]);
	}
	qsort(person, num, sizeof(int), compare);
	for (i = 0; i < num; i++)
	{
		use_time += person[i];
		total += use_time;
	}
	printf("%d", total);
	return 0;
}
