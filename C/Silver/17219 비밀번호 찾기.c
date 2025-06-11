/*
1. 해시 테이블 구성
2. 띄어쓰기 단위로 sscanf 파싱
3. 해시 테이블 이용해서 출력
*/

#define TABLE_SIZE 131072
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct entry
{
	char address[21];
	char password[21];
	int used;
} Entry;

Entry table[TABLE_SIZE];

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

int main(void)
{
	int i, site, find, index, start;
	char line[42], address[21], password[21];
	scanf("%d %d", &site, &find);
	getchar();
	for (i = 0; i < site; i++)
	{
		scanf("%s %s", address, password);
		index = hash(address);
		while (table[index].used)
		{
			index = (index + 1) % TABLE_SIZE;
		}
		strcpy(table[index].address, address);
		strcpy(table[index].password, password);
		table[index].used = 1;
	}
	for (i = 0; i < find; i++)
	{
		scanf("%s", line);
		index = hash(line);
		start = index;
		while (table[index].used)
		{
			if (strcmp(line, table[index].address) == 0)
			{
				printf("%s\n", table[index].password);
			}
			index = (index + 1) % TABLE_SIZE;
			if (index == start)
			{
				break;
			}
		}
	}
	return 0;
}