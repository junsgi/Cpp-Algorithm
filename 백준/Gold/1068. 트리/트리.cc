#pragma warning(disable:4996)
#include<stdio.h>
#include<vector>
#include<string>
#define MAX 0x7fffffff
using namespace std;
int n, t, root, del, ans, visit[51], cnt[51];
int max(int a, int b) { return a < b ? b : a; }
int min(int a, int b) { return a > b ? b : a; }
vector<int> graph[51];

void post(int node)
{
	visit[node] = 1;
	for (int i = 0; i < (int)graph[node].size(); i++)
	{
		if (!visit[graph[node][i]] && graph[node][i] != del)
		{
			cnt[node]++;
			post(graph[node][i]);
		}
	}
	if (cnt[node] == 0) ans++;
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &t);
		if (t == -1) root = i;
		else
		{
			graph[t].push_back(i);
			graph[i].push_back(t);

		}
	}
	scanf("%d", &del);
	if (del != root) post(root);
	printf("%d", ans);
	return 0;
}