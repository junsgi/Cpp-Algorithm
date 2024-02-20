#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
struct temp {
	int st, ed;
};
int n, t, check[1'000'001], cnt, seg[1 << 20];
long long ans;
int insert(int left, int right, int idx, int value)
{
	if (value < left || right < value) return seg[idx];
	if (left == value && right == value)
		return seg[idx] += 1;
	int mid = (left + right) / 2;
	return seg[idx] = insert(left, mid, idx * 2, value) + insert(mid + 1, right, idx * 2 + 1, value);

}
int query(int left, int right, int idx, int start, int end)
{
	if (end < left || right < start) return 0;
	if (start <= left && right <= end)
		return seg[idx];
	int mid = (left + right) / 2;
	return query(left, mid, idx * 2, start, end) + query(mid + 1, right, idx * 2 + 1, start, end);
}
int main()
{
	scanf("%d", &n);
	for (cnt = 1; cnt <= n; cnt *= 2);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &t);
		check[t] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &t);
		ans += query(1, cnt, 1, check[t], cnt);
		insert(1, cnt, 1, check[t]);
	}
	printf("%lld", ans);
	return 0;
}