#pragma warning(disable:4996)
#include<stdio.h>
#include<vector>
#include<string>
#define MAX 0x7fffffff
using namespace std;
int n, cnt, ans1 = MAX, ans2, m, visit[10001];
pair<int, int> check[10001];
vector<int> arr[10001];
int p, l, r;
int max(int a, int b) { return a < b ? b : a; }
int min(int a, int b) { return a > b ? b : a; }
void inorder(int node, int depth)
{
	if (node == -1) return;
	m = max(m, depth);
	inorder(arr[node][0], depth + 1);
	check[depth].first = min(check[depth].first, ++cnt);
	check[depth].second = max(check[depth].second, cnt);
	inorder(arr[node][1], depth + 1);
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		check[i] = {MAX, 0};
		scanf("%d%d%d", &p, &l, &r);
		arr[p].push_back(l);
		arr[p].push_back(r);
		if (l != -1) visit[l]++;
		if (r != -1) visit[r]++;
	}
	int root = 0;
	for (int i = 1; i <= n; i++)
	{
		if (visit[i] == 0)
		{
			root = i;
			break;
		}
	}
	inorder(root, 1);
	for (int i = 1; i <= n; i++)
	{
		if (ans2 < check[i].second - check[i].first + 1)
		{
			ans1 = i;
			ans2 = check[i].second - check[i].first + 1;
		}
	}
	printf("%d %d", ans1, ans2);
	return 0;
}