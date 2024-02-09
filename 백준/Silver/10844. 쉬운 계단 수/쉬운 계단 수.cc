#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
#define MOD 1'000'000'000
using namespace std;
typedef long long ll;
int n, ans;
int DP[101][10];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= 9; i++) DP[1][i] = 1;
	for (int i = 2; i <= 100; i++)
	{
		DP[i][0] = DP[i - 1][1];
		DP[i][9] = DP[i - 1][8];
		for (int j = 1; j <= 8; j++)
			DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j + 1]) % MOD;
	}
	for (int i = 0; i < 10; i++) ans = (ans + DP[n][i]) % MOD;
	printf("%d", ans % MOD);
	return 0;
}