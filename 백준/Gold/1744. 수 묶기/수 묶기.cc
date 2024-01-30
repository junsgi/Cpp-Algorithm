#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> p, m;
int n, len, ans, t;
int cmp(int a, int b) { return a > b; }
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &t);
		if (t > 0) p.push_back(t);
		else m.push_back(t);
	}
	sort(p.begin(), p.end(), cmp);
	sort(m.begin(), m.end());
	int idx = 0;
	for (idx = 1; idx < (int)p.size(); idx += 2)
	{
		int c1 = p[idx - 1] * p[idx];
		int c2 = p[idx - 1] + p[idx];
		if (c1 > c2) ans += c1;
		else ans += c2;
	}
	if (p.size() % 2)
		ans += p[(int)p.size() - 1];

	for (idx = 1; idx < (int)m.size(); idx += 2)
	{
		int c1 = m[idx - 1] * m[idx];
		int c2 = m[idx - 1] + m[idx];
		if (c1 < c2) ans += c2;
		else ans += c1;
	}
	if (m.size() % 2)
		ans += m[(int)m.size() - 1];
	printf("%d", ans);
	return 0;
}
