/*
1. 해시맵 코드 작성
2. 파싱 입력
3. (n+1)*(m+1)-1 로 계산하기

*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TABLE_SIZE 131072

typedef struct entry
{
	int count;
	char category[21];
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
	int n, num, i, j, result, index, found, start;
	char line[50];
	char name[21];
	char temp[21];
	scanf("%d", &n);
	getchar();
	for (i = 0; i < n; i++)
	{
		result = 1;
		scanf("%d", &num);
		getchar();
		for (j = 0; j < num; j++)
		{
			found = 0;
			fgets(line, sizeof(line), stdin);
			sscanf(line, "%s %s", name, temp);
			index = hash(temp);
			start = index;
			while (table[index].used)
			{
				if (!strcmp(temp, table[index].category))
				{
					table[index].count++;
					found = 1;
					break;
				}
				index = (index + 1) % TABLE_SIZE;
				if (start == index) break;
			}
			if (!found)
			{
				strcpy(table[index].category, temp);
				table[index].used = 1;
				table[index].count = 1;
			}

		}
		for (j = 0; j < TABLE_SIZE; j++)
		{
			if (table[j].used)
			{
				result *= (table[j].count + 1);
			}
		}
		result -= 1;
		printf("%d\n", result);
		memset(table, 0, sizeof(table));
	}
	return 0;
}
