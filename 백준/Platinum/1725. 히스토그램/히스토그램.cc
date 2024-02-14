#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
#define MAX(x, y)( ((x)>(y)) ? (x) : (y) )
#define M 0x7fffffff
using namespace std;
typedef pair<int, int> temp;
int n, cnt, a, i, ans;
temp seg[1 << 18];
temp MIN(temp a, temp b) { return a.first < b.first ? a : b; }
temp insert(int left, int right, int idx)
{
	int mid = (left + right) / 2;
	if (i < left || right < i) return seg[idx];
	if (left == i && right == i) return seg[idx] = {a, i};
	return seg[idx] = MIN(insert(left, mid, idx * 2), insert(mid + 1, right, idx * 2 + 1));
}
temp query(int left, int right, int idx, int st, int ed)
{
	int mid = (left + right) / 2;
	if (ed < left || right < st) return make_pair(M, M);
	if (st <= left && right <= ed) return seg[idx];
	return MIN(query(left, mid, idx * 2, st, ed), query(mid + 1, right, idx * 2 + 1, st, ed));
}
void 분할(int left, int right)
{
	if (left > right) return;
	temp tmp = query(1, cnt, 1, left, right);
	ans = MAX(ans, tmp.first * (right - left + 1));
	분할(left, tmp.second - 1);
	분할(tmp.second + 1, right);
}
int main()
{
	scanf("%d", &n);
	for (cnt = 1; cnt <= n; cnt *= 2);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &a);
		insert(1, cnt, 1);
	}
	분할(1, n);
	printf("%d", ans);
	return 0;
}