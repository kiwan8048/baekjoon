/*
1. �赵 ���� ���� ����� �ؽ� ���̺� ����
2. ���� ���� ����� �Է� ������ �ؽ� ���̺� �ִ��� üũ, ������ count 1 �ø��� ���
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TABLE_SIZE 131072

typedef struct entry
{
	char name[21];
	int used;
} Entry;

Entry table[TABLE_SIZE];
char save[500001][21];

unsigned int hash(const char* str)
{
	unsigned long hash = 5381;
	int c;
	while (c = *str++)
	{
		hash = 33 * hash + c;
	}
	return hash % TABLE_SIZE;
}

int compare(const void* a, const void* b)
{
	return strcmp((const char*)a, (const char*)b);
}

int main(void)
{
	int i, N, M, index, count = 0;
	char line[21];
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++)
	{
		scanf("%s", line);
		index = hash(line);
		while (table[index].used)
		{
			index = (index + 1) % TABLE_SIZE;
		}
		strcpy(table[index].name, line);
		table[index].used = 1;
	}
	for (i = 0; i < M; i++)
	{
		scanf("%s", line);
		index = hash(line);
		int start = index;
		while (table[index].used)
		{
			if (strcmp(table[index].name, line) == 0)
			{
				strcpy(save[count], line);
				count++;
				break;
			}
			index = (index + 1) % TABLE_SIZE;
			if (index == start)
				break;
		}
	}
	printf("%d\n", count);
	qsort(save, count, sizeof(save[0]), compare);
	for (i = 0; i < count; i++)
	{
		printf("%s\n", save[i]);
	}
	return 0;
}