#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
#include<vector>
#define M 1'000'000'000
using namespace std;
int T, n, m, w, a, b, c, visit[1000];
struct temp {
	int st, ed, value;
};
vector<temp> arr;
int main()
{
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf("%d%d%d", &n, &m, &w);
		fill(&visit[0], &visit[n], 0);
		for (int j = 0; j < m; j++)
		{
			scanf("%d%d%d", &a, &b, &c);
			arr.push_back({ a, b, c });
			arr.push_back({ b, a, c });
		}
		for (int j = 0; j < w; j++)
		{
			scanf("%d%d%d", &a, &b, &c);
			arr.push_back({ a, b, -c });
		}
		int hit = 0;
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < (int)arr.size(); k++)
			{
				if (visit[arr[k].ed] > visit[arr[k].st] + arr[k].value)
				{
					visit[arr[k].ed] = visit[arr[k].st] + arr[k].value;
					if (j == n - 1) hit = 1;
				}
			}
		}
		if (hit) printf("YES\n");
		else printf("NO\n");
		arr.clear();

	}
	return 0;
}