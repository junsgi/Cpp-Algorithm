#pragma warning(disable:4996)
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, t, k, D, ans, ax, ay;
int dire[4][2] = { {-1 ,0}, {1, 0}, {0, -1}, {0, 1} };
vector<int> x, y;
void pro(int tx, int ty)
{
	int rx = tx + k, ry = ty + k;
	int cnt = 0;
	for (int idx = 0; idx < t; idx++)
	{
		if (tx <= x[idx] &&
			x[idx] <= rx &&
			ty <= y[idx] &&
			y[idx] <= ry)
			cnt++;
	}
	int cx = tx + D;
	int cy = ty + D;
	cy = (cx + cy) / 2;
	cx = cx - cy;
	if (0 <= cx && cx <= n && 0 <= cy && cy <= m && ans < cnt)
	{
		ans = cnt;
		ax = cx;
		ay = cy;
	}

}
int main()
{
	scanf("%d%d%d%d", &n, &m, &t, &k);
	D = k / 2;
	for (int i = 0; i < t; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		x.push_back(a + b); y.push_back(b - a);
	}
	for (int i = 0; i < t; i++)
	{
		for (int j = 0; j < t; j++)
		{
			if ((x[i] + y[j]) % 2 == 0)
				pro(x[i], y[j]);
			else
			{
				for (int d = 0; d < 4; d++)
					pro(x[i] + dire[d][0], y[j] + dire[d][1]);
			}
			pro(x[i] - D, y[j] - D);
		}
	}
	printf("%d %d\n%d", ax, ay, ans);
	return 0;
}
