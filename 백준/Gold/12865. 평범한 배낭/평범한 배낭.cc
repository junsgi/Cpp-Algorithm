#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
using namespace std;
int n, m, k, v;
int DP[101][100'001];
int max(int a, int b) { return a < b ? b : a; }
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &k, &v);
		for (int j = 1; j <= m; j++)
		{
			// 안 넣는다.
			DP[i][j] = DP[i - 1][j];

			if (j - k >= 0) // 현재 보석을 가방에 넣을 수 있을 때
				DP[i][j] = max(DP[i][j], DP[i - 1][j - k] + v);
			// 현재 보석의 가치와 이전 보석(가방의 남은 공간)의 가치를 비교
		}
	}
	printf("%d", DP[n][m]);
	return 0;
}