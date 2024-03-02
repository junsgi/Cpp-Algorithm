#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int n, st, ed, m, freq[100], a, b, c, status;
long long M = -100'000'000'000'000, visit[100], cost[100];
struct temp {
	int st, ed, value;
};
vector<temp> arr;
int main()
{
	scanf("%d%d%d%d", &n, &st, &ed, &m);
	fill(&visit[0], &visit[n], M);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &a, &b, &c);
		arr.push_back({ a, b, -c });
	}
	for (int i = 0; i < n; i++) scanf("%lld", &cost[i]);
	visit[st] = cost[st];
	int status = 0;
	for (int i = 0; i < n + 101; i++)
	{
		status = 0;
		for (int j = 0; j < (int)arr.size(); j++)
		{
			if (visit[arr[j].st] == M) continue;
			else if (visit[arr[j].st] == -M)
				visit[arr[j].ed] = -M;
			else if (visit[arr[j].ed] < visit[arr[j].st] + cost[arr[j].ed] + arr[j].value)
			{
				visit[arr[j].ed] = visit[arr[j].st] + cost[arr[j].ed] + arr[j].value;
				// 마지막에 영향을 주는 지점의 값이 바뀐다면
				if (i >= n - 1)
				{
					visit[arr[j].ed] = -M;
					if (arr[j].ed == ed)
					{
						status = 1;
						break;
					}
				}
			}
		}
		if (status) break;
	}
	if (visit[ed] == -M) printf("Gee");
	else if (visit[ed] == M) printf("gg");
	else printf("%lld", visit[ed]);
	return 0;
}