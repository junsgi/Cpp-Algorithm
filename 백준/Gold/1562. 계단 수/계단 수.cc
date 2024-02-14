#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
#define MOD 1'000'000'000
using namespace std;
typedef long long ll;
int n;
ll DP[101][10][1 << 10], ans;
int main()
{
	scanf("%d", &n);
	/*
	숫자를 한 개만 사용하였을 때
	1은 (0 ~ 9) 숫자 중 1만 사용
	2는 (0 ~ 9) 숫자 중 2만 사용
	...
	9는 (0 ~ 9) 숫자 중 9만 사용
	*/
	for (int i = 1; i <= 9; i++)
		DP[1][i][1 << i] = 1;


	for (int i = 2; i <= n; i++) // 사용할 숫자의 개수 (자릿수)
	{
		for (int j = 0; j <= 9; j++) // 가장 뒤에 오는 숫자
		{
			for (int k = 1; k < (1 << 10); k++) // 10개의 비트를 사용하거나 안 했을 때의 경우의 수
			{
				if (j != 9) 
					DP[i][j][k | (1 << j)] += DP[i - 1][j + 1][k];

				if (j != 0) 
					DP[i][j][k | (1 << j)] += DP[i - 1][j - 1][k];

				DP[i][j][k | (1 << j)] %= MOD;
			}
		}
	}

	for (int i = 0; i < 10; i++)
		ans = (ans + DP[n][i][(1 << 10) - 1]) % MOD;
	printf("%lld", ans % MOD);
	return 0;
}