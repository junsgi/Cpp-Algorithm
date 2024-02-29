#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
using namespace std;
int n, X, Y;
struct temp {
	double x, y, width, height;
}rec[100];
double x[100], y[100], ans;
double getArea(double a, double b, double x, double y)
{
	return abs((x - a) * (y - b));
}
int check(double a, double b, double x, double y)
{
	for (int i = 0; i < n; i++)
	{
		if (rec[i].x <= a &&
			x <= rec[i].width &&
			rec[i].y <= b &&
			y <= rec[i].height)
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lf%lf%lf%lf", &rec[i].x, &rec[i].y, &rec[i].width, &rec[i].height);
		rec[i].width += rec[i].x;
		rec[i].height += rec[i].y;
		x[X++] = rec[i].x;
		x[X++] = rec[i].width;

		y[Y++] = rec[i].y;
		y[Y++] = rec[i].height;
	}
	sort(x, x + X);
	sort(y, y + Y);
	for (int i = 0; i < X - 1; i++)
	{
		double a = x[i];
		double b = x[i + 1];
		if (a == b) continue;
		for (int j = 0; j < Y - 1; j++)
		{
			double c = y[j];
			double d = y[j + 1];
			if (c == d) continue;
			int flag = check(a, c, b, d);
			if (flag)
				ans += (b - a) * (d - c);
		}
	}
	if ((long long)ans == ans) printf("%lld", (long long)ans);
	else
		printf("%.2lf", ans);
	return 0;
}