/*
1. �����ķ� ���� �ð� ������ ����
2. ù ����ڰ� �ɸ��� �ð��� use_time���� ����, total�� ����
3. ���� ����ڰ� �ɸ��� ���� use_time���ٰ� ���ؼ� �����ϰ�, total�� use_time ���ؼ� ����
4. ���
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
