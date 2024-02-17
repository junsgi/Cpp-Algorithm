#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
using namespace std;
typedef double ll;

int n;
ll x1, y11, x2, y2, x3, y3;
ll ans;
ll CCW(ll a, ll b, ll c, ll d, ll e, ll f)
{
	ll t1 = a * d + c * f + e * b;
	ll t2 = c * b + e * d + a * f;
	return (t1 - t2) / 2;
}
int main()
{
	scanf("%d", &n);
	scanf("%lf%lf%lf%lf", &x1, &y11, &x2, &y2);
	for (int i = 0; i < n - 2; i++)
	{
		scanf("%lf%lf", &x3, &y3);
		ans += CCW(x1, y11, x2, y2, x3, y3);
		x2 = x3;
		y2 = y3;
	}
	printf("%.1lf", abs(ans));
	return 0;
}