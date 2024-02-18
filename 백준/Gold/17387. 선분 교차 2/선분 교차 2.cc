#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
using namespace std;
typedef long long ll;
ll a1, b1, a2, b2, a3, b3, a4, b4;
int CCW(ll a, ll b, ll c, ll d, ll e, ll f)
{
	ll res = (a * d + c * f + e * b) - (c * b + e * d + a * f);
	if (res < 0) return -1;
	if (res > 0) return 1;
	return 0;
}
int main()
{
	scanf("%lld%lld%lld%lld%lld%lld%lld%lld", &a1, &b1, &a2, &b2, &a3, &b3, &a4, &b4);
	int res1 = CCW(a1, b1, a2, b2, a3, b3) * CCW(a1, b1, a2, b2, a4, b4);
	int res2 = CCW(a3, b3, a4, b4, a1, b1) * CCW(a3, b3, a4, b4, a2, b2);
	ll flag = 0;
	if (res1 == 0 && res2 == 0)
	{
		flag =
			min(a1, a2) <= max(a3, a4) &&
			min(a3, a4) <= max(a1, a2) &&
			min(b1, b2) <= max(b3, b4) &&
			min(b3, b4) <= max(b1, b2);
	}
	else if (res1 <= 0 && res2 <= 0)
		flag = 1;
	printf("%lld", flag);
	return 0;
}