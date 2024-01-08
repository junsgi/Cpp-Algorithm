#pragma warning(disable:4996)
#include<stdio.h>
char a[100];
int temp, swi = 1, ans, plus;
int main()
{
	scanf("%s", a);
	for (int i = 0; a[i]; i++)
	{
		if (a[i] == '-' || a[i] == '+')
		{
			if (a[i] == '-') swi = -1;
			ans += temp;
			temp = 0;
		}
		else
			temp = temp * 10 + (a[i] - '0') * swi;
	}
	printf("%d", ans + temp);
	return 0;
}
