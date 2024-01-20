#pragma warning(disable:4996)
#include<stdio.h>
#include<vector>
using namespace std;
// 0일 때 0은 한 번 1은 0번
// 1일 때 0은 0번 1은 한 번
int zero[50] = { 1, 0, 1,}, one[50] = { 0, 1, 1};
int n, t;
int main()
{
	for (int i = 3; i < 50; i++)
	{
		zero[i] = zero[i - 1] + zero[i - 2];
		one[i] = one[i - 1] + one[i - 2];
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &t);
		printf("%d %d\n", zero[t], one[t]);
	}
	return 0;
}
