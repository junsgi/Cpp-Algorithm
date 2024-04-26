#pragma warning(disable:4996)
#include <stdio.h>
#include <algorithm>
#define M 2'000'000'000
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int n, ex, arr[100'001];
ll ans;
pii seg[1 << 18];

pii insert(int left, int right, int idx);
pii query(int left, int right, int idx, int x, int y);
void process(int left, int right);
int main()
{
	while (1)
	{
		scanf("%d", &n);
		if (!n) break;
		ans = 0;
		for (ex = 1; ex <= n; ex *= 2);
		for (int i = 1; i <= ex; i++) seg[i].first = seg[i].second = M;
		for (int i = 1; i <= n; i++)
			scanf("%d", &arr[i]);
		insert(1, n, 1);
		process(1, n);
		printf("%lld\n", ans);
	}
	return 0;
}

pii insert(int left, int right, int idx)
{
	if (left == right) return seg[idx] = {arr[left], left};
	int mid = (left + right) / 2;
	pii a = insert(left, mid, idx * 2);
	pii b = insert(mid + 1, right, idx * 2 + 1);
	if (a.first < b.first) seg[idx] = a;
	else seg[idx] = b;
	return seg[idx];
}
pii query(int left, int right, int idx, int x, int y)
{
	if (y < left || right < x) return { M, -1 };
	if (x <= left && right <= y) return seg[idx];
	int mid = (left + right) / 2;
	pii a = query(left, mid, idx * 2, x, y);
	pii b = query(mid + 1, right, idx * 2 + 1, x, y);
	if (a.first < b.first) return a;
	else return b;
}

void process(int left, int right)
{
	if (left > right) return;
	pii MIN = query(1, n, 1, left, right);
	ans = max(ans, (ll)(right - left + 1) * MIN.first);
	process(left, MIN.second - 1);
	process(MIN.second + 1, right);
}