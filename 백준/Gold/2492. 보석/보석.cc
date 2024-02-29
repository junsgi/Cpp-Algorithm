#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
struct temp 
{
	int x, y;
};
vector<int> x, y;
int n, m, t, k, a, b, ans, ax, ay;
void sweeping()
{
	for (int i = 0; i < t; i++)
	{
		for (int j = 0; j < t; j++)
		{
			int x1 = x[i];
			int y1 = y[j] - k;
			int x2 = x1 + k;
			int y2 = y[j];
			int sum = 0;
			for (int s = 0; s < t; s++)
			{
				if (x1 <= x[s] &&
					x[s] <= x2 &&
					y1 <= y[s] &&
					y[s] <= y2) sum++;
			}
			if (sum > ans)
			{
				ans = sum;
				ax = min(x1, n - k);
				ay = max(y2, k);
			}
		}
	}
}
int main()
{
	scanf("%d%d%d%d", &n, &m, &t, &k);
	for (int i = 0; i < t; i++)
	{
		scanf("%d%d", &a, &b);
		x.push_back(a);
		y.push_back(b);
	}
	sweeping();
	printf("%d %d\n%d", ax, ay, ans);
	return 0;
}