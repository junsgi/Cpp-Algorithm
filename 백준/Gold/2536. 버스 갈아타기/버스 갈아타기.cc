#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
struct temp {
	int n, a, b, c, d;
};
int n, m, k, sx, sy, ex, ey, visit[5001];
vector<temp> arr;
queue<temp> que;
int CCW(ll a, ll b, 
		ll c, ll d, 
		ll e, ll f)
{
	long long t1 = (a * d + c * f + e * b);
	long long t2 = (c * b + e * d + a * f);
	long long res = t1 - t2;
	if (res < 0) return -1;
	if (res > 0) return 1;
	return 0;
}
int check(int a, int b, 
		  int c, int d,	
		  int e, int f, 
		  int g, int h)
{
	int res1 = CCW(a, b, c, d, e, f) * CCW(a, b, c, d, g, h);
	int res2 = CCW(e, f, g, h, a, b) * CCW(e, f, g, h, c, d);
	if (res1 == 0 && res2 == 0)
	{
		return
			min(a, c) <= max(e, g) &&
			min(e, g) <= max(a, c) &&
			min(b, d) <= max(f, h) &&
			min(f, h) <= max(b, d);
	}
	if (res1 <= 0 && res2 <= 0) return 1;
	return 0;
}
int on(int a, int b, int c, int d, int e, int f)
{
	return
		min(a, c) <= e &&
		e <= max(a, c) &&
		min(b, d) <= f &&
		f <= max(b, d);
}
int BFS()
{
	for (int i = 0; i < (int)arr.size(); i++)
	{
		if (on(arr[i].a, arr[i].b, arr[i].c, arr[i].d, sx, sy))
		{
			que.push({ arr[i].n, arr[i].a, arr[i].b, arr[i].c, arr[i].d });
			visit[arr[i].n] = 1;
		}
	}

	while (!que.empty())
	{
		temp tmp = que.front(); que.pop();
		if (on(tmp.a, tmp.b, tmp.c, tmp.d, ex, ey))
			return visit[tmp.n];
		for (int i = 0; i < (int)arr.size(); i++)
		{
			if (visit[arr[i].n]) continue;
			if (!check(tmp.a, tmp.b, tmp.c, tmp.d, arr[i].a, arr[i].b, arr[i].c, arr[i].d)) continue;
			visit[arr[i].n] = visit[tmp.n] + 1;
			que.push({ arr[i].n, arr[i].a, arr[i].b, arr[i].c, arr[i].d });
		}
	}
	return 0;

}
int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < k; i++)
	{
		int  no, a, b, c, d;
		scanf("%d%d%d%d%d", &no, &a, &b, &c, &d);
		arr.push_back({ no, a, b , c , d });
	}
	scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
	printf("%d", BFS());
	return 0;
}