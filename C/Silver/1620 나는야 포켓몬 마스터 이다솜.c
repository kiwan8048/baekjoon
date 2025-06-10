/*
1. 해시 함수 구성
2. 문자열 입력 받아 해시 함수로 해시값 받기
3. 출력
*/

#define _CRT_SECURE_NO_WARNINGS
#define TABLE_MAX 131072
#include <stdio.h>
#include <string.h>
#include <ctype.h>
typedef struct entry
{
	int num;
	char name[21];
	int used;
} Entry;

Entry table[TABLE_MAX];

unsigned int hash(const char *str)
{
	unsigned hash = 5381;
	int c;
	while (c = *str++)
	{
		hash = 33 * hash + c;
	}
	return hash % TABLE_MAX;
}

char names[100000][21];

int main(void)
{
	int i, count, quest, index, atoi_num;
	char line[21];
	scanf("%d %d", &count, &quest);
	for (i = 0; i < count; i++)
	{
		scanf("%s", line);
		strcpy(names[i], line);
		index = hash(line);
		while (table[index].used)
		{
			index = (index + 1) % TABLE_MAX;
		}
		table[index].num = i;
		strcpy(table[index].name, line);
		table[index].used = 1;
	}
	for (i = 0; i < quest; i++)
	{
		scanf("%s", line);
		if (isdigit(line[0])) // 숫자로 시작
		{
			atoi_num = atoi(line);
			printf("%s\n", names[atoi_num - 1]);
		}
		else // 문자로 시작
		{
			index = hash(line);
			while (table[index].used) 
			{
				if (strcmp(table[index].name, line) == 0)
				{
					printf("%d\n", table[index].num + 1);
					break;
				}
				index = (index + 1) % TABLE_MAX;
			}
		}
	}
	return 0;
}