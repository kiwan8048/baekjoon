/*
1. ��ü ���� �Է� �ޱ�
2. ����� ���� �ʴ� ���� ū ���� ã�� ���������� �ִ븸ŭ ����, count ���� ����ŭ �ø���
3. ����� �����¸�ŭ �����ϱ�
4. �ݺ�
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
