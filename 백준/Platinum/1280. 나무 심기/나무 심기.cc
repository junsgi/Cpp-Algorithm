#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
#define MOD 1'000'000'007
using namespace std;
typedef long long ll;
typedef pair<ll, ll> temp;
int n, a, cnt, arr[1 << 18], MAX;
temp seg[1 << 19];
ll sum, answer= 1;
temp insert(int left, int right, int idx)
{
	int mid = (left + right) / 2;
	if (a < left || right < a) return seg[idx];
	if (left == right)
	{
		seg[idx].first += a;
		seg[idx].second++;
		return seg[idx];
	}
	temp le = insert(left, mid, idx * 2);
	temp ri = insert(mid + 1, right, idx * 2 + 1);
	return seg[idx] = { le.first + ri.first, le.second + ri.second };
}
temp query(int left, int right, int idx, int st, int ed)
{
	int mid = (left + right) / 2;
	if (ed < left || right < st) return {0, 0};
	if (st <= left && right <= ed) return seg[idx];
	temp le = query(left, mid, idx * 2, st, ed);
	temp ri = query(mid + 1, right, idx * 2 + 1, st, ed);
	return { le.first + ri.first, le.second + ri.second };
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &arr[i]);
		arr[i]++;
		MAX = MAX < arr[i] ? arr[i] : MAX;
	}
	for (cnt = 1; cnt <= MAX; cnt *= 2);
	a = arr[1];
	insert(1, cnt, 1);
	for (int i = 2; i <= n; i++)
	{
		a = arr[i];
		temp left = query(1, cnt, 1, 1, a - 1);
		ll L = abs(arr[i] * left.second - left.first);
		L %= MOD;

		temp right = query(1, cnt, 1, a + 1, cnt);
		ll R = abs(arr[i] * right.second - right.first);
		R %= MOD;

		answer = (answer % MOD * (L + R));
		answer %= MOD;

		insert(1, cnt, 1);
	}
	printf("%lld\n", answer % MOD);
	return 0;
}
/*
4
1
8
15
1
3087

cur = 7
left = 3, 4, 5
right = 9, 15, 21

left result = (7 - 3) + (7 - 4) + (7 - 5)
left result = 7 * 3 - (3 + 4 + 5)


right result = |(7 - 8) + (7 - 15) + (7 - 20)|
right result = 7 * 3 - (8 + 15 + 20)
*/