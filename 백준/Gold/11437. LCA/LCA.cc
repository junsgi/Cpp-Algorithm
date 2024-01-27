#pragma warning(disable:4996)
#include<stdio.h>
#include<vector>
#include<string>
#define MAX 100'001
using namespace std;
int n, depth[MAX], pa[MAX];
int max(int a, int b) { return a < b ? b : a; }
int min(int a, int b) { return a > b ? b : a; }
vector<int> graph[MAX];
/*
LCA
1. 루트에서부터 모든 노드의 깊이를 구한다.
2. 두 노드 사이의 깊이를 같게 한다.
3. 두 노드가 서로 다르다면 각 노드의 부모로 이동한다.
4. 두 노드가 다르다면 3번 과정을 반복
5. 같다면 현재 값이 두 노드의 최소 공통 조상
*/
void DFS(int node)
{
	for (int i = 0; i < (int)graph[node].size(); i++)
	{
		if (depth[graph[node][i]] != -1) continue;
		depth[graph[node][i]] = depth[node] + 1; // 깊이 저장
		pa[graph[node][i]] = node; // 부모 저장
		DFS(graph[node][i]);
	}
}
int main()
{
	scanf("%d", &n);
	fill(depth, depth + n + 1, -1);
	depth[1] = 0;
	for (int i = 0; i < n - 1; i++)
	{
		int st, ed;
		scanf("%d%d", &st, &ed);
		graph[st].push_back(ed);
		graph[ed].push_back(st);
	}
	DFS(1);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int n1, n2;
		scanf("%d%d", &n1, &n2);

		while (depth[n1] != depth[n2]) // 깊이가 같지 않다면 깊이를 맞춘다.
		{
			if (depth[n1] < depth[n2])
				n2 = pa[n2];
			else
				n1 = pa[n1];
		}
		while (n1 != n2) // 서로 같지 않다면 조상 노드로 바꾼다.
		{
			n1 = pa[n1];
			n2 = pa[n2];
		}
		printf("%d\n", n1);
	}
	return 0;
}
