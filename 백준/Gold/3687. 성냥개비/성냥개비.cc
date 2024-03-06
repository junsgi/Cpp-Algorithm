#pragma warning(disable:4996)
#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#define M "1000000000"
using namespace std;
typedef long long ll;
int t, n;
string DP[101] = { M, M, "1", "7", "4", "2", "0", "8" };
ll heap[101], len;
void up(int idx);
void dynamic();
int main()
{
	dynamic();
	DP[6] = "6";
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%d", &n);
		int origin = n;
		string tmp = "";
		if (n % 2)
		{
			tmp = "7";
			n -= 3;
		}
		for (int i = 0; i < n / 2; i++)
			tmp.append("1");
		cout << DP[origin] << " " << tmp << '\n';
	}
	return 0;
}
void dynamic()
{
	for (int i = 8; i <= 100; i++)
	{
		string res = M;
		for (int j = 2; j <= i / 2; j++)
		{
			string a;
			if (DP[j].at(0) == '0') a = "6" + DP[i - j];
			else a = DP[j] + DP[i - j];

			string b = DP[i - j] + DP[j];
			if (DP[i - j].at(0) == '0') b = "6" + DP[j];
			else b = DP[i - j] + DP[j];

			heap[++len] = stoll(a);
			up(len);

			heap[++len] = stoll(b);
			up(len);
		}
		DP[i] = to_string(heap[1]);
		len = 0;
		heap[1] = 0;
	}
}
void up(int idx)
{
	int child = idx / 2;
	if (child <= 0) return;
	if (heap[idx] < heap[child])
	{
		ll tmp = heap[idx];
		heap[idx] = heap[child];
		heap[child] = tmp;
		up(child);
	}
}