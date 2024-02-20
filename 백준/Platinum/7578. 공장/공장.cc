/*
0. 두 번째 줄 입력부터 차례대로 줄을 확인해야 하기 때문에 도착지점 이후의 줄 개수만 알면 됨
1. 두 번째 줄 입력부터 연결되어야 하는 위치를 기준으로 줄의 개수를 기록하여 세그먼트 트리를 만듦
2. 두 번째 줄 입력의 도착 지점 이후에 줄의 개수를 셈
*/
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
