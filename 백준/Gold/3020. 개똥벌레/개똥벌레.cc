#pragma warning(disable:4996)
#include <algorithm>
#include <queue>
#include <string>
#include <iostream>
using namespace std;
int n, h, cnt;
int ps[500'200], MIN = 0x7fffffff;
int main()
{
	cin >> n >> h;

	for (int i = 0; i < n; i++)
	{
		int N;
		cin >> N;
		ps[i % 2 ? 1 : h - N + 1]++;
		ps[i % 2 ? N + 1 : h + 1]--;
	}
	for (int i = 1; i <= h; i++)
	{
		ps[i] += ps[i - 1];
		if (ps[i] < MIN)
		{
			cnt = 1;
			MIN = ps[i];
		}
		else if (ps[i] == MIN) cnt++;
		
	}
	cout << MIN << " " << cnt;
	return 0;
}