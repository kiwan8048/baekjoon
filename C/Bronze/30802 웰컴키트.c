#include <stdio.h>

int main(void)
{
	int n, i, count = 0, bundle_T = 0, bundle_pen = 0;
	int size[6];
	scanf("%d", &n);
	scanf("%d %d %d %d %d %d", &size[0], &size[1], &size[2], &size[3], &size[4], &size[5]);
	scanf("%d %d", &bundle_T, &bundle_pen);
	for (i = 0; i < 6; i++)
	{
		count += (size[i] / bundle_T) + 1;
		if (size[i] % bundle_T == 0)
		{
			count--;
		}
	}
	printf("%d\n", count);
	printf("%d ", n / bundle_pen);
	printf("%d", n % bundle_pen);
	return 0;
}