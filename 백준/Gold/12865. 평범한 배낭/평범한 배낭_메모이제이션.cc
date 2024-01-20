#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
using namespace std;
/*
  사용한 보석의 개수(깊이)가 같고, 남아있는 배낭의 공간이 같을 때 데이터 재사용 가능
*/
int n, m, weight[200], value[200], a, b, ans;
int DP[101][100'001];
int max(int a, int b) { return a < b ? b : a; }

int DFS(int idx, int w)
{
	if (idx > n) return 0;
	if (DP[idx][w]) 
		return DP[idx][w];
	int a = 0, b;
	if (w + weight[idx] <= m)
		a = DFS(idx + 1, w + weight[idx]) + value[idx];
	b = DFS(idx + 1, w);
	DP[idx][w] = max(a, b);
	return DP[idx][w];
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) 
		scanf("%d%d", &weight[i], &value[i]);
	
	printf("%d", DFS(1, 0));
	return 0;
}
