#pragma warning(disable:4996)
#include <stdio.h>
int n, stk[100001], arr[100001], ed = -1, tmp, a, idx;
char ans[200001];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	for (int i = 1; i <= n; i++)
	{
		if (ed == -1 || idx < n && i <= arr[idx])
		{
			stk[++ed] = i;
			ans[a++] = '+';
		}
		else
		{
			while (1)
			{
				if (ed == -1 || idx >= n || stk[ed] != arr[idx]) break;
				ed--;
				ans[a++] = '-';
				idx += 1;
			}
			stk[++ed] = i;
			ans[a++] = '+';
		}
	}
	while (1)
	{
		if (ed == -1 || stk[ed] != arr[idx]) break;
		ed--;
		ans[a++] = '-';
		idx += 1;
	}
	if (ed != -1) printf("NO");
	else
		for (int i = 0; i < a; i++)printf("%c\n", ans[i]);
	return 0;
}