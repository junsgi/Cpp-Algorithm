#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
int n, m, S;
char com[10];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", &com);
		scanf("%d", &m);
		int num = m - 1;
		if (!strcmp(com, "add"))
			S |= (1 << num);
		else if (!strcmp(com, "remove"))
			S &= ~(1 << num);
		else if (!strcmp(com, "check"))
			printf("%d\n", S & (1 << num) ? 1 : 0);
		else if (!strcmp(com, "toggle"))
			S = S & (1 << num) ? S & ~(1 << num) : S | (1 << num);
		else if (!strcmp(com, "all"))
			S = (1 << 20) - 1;
		else
			S = 0;
	}
	return 0;
}