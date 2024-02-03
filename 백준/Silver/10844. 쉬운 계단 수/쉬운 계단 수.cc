#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#define M 1'000'000'000
int n;
long long DP[101][10];
int main()
{
	for (int i = 1; i < 10; i++) DP[1][i] = 1;
	for (int i = 2; i <= 100; i++)
	{
		DP[i][0] = DP[i - 1][1];
		DP[i][9] = DP[i - 1][8];
		for (int j = 1; j < 9; j++)
			DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j + 1]) % M;
	}
	scanf("%d", &n);
	long long result = 0;
	for (int i = 0; i < 10; i++)
		result += DP[n][i] % M;
	printf("%lld", result % M);
	return 0;
}