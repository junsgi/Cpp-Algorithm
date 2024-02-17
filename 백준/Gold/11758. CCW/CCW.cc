#pragma warning(disable:4996)
#include<stdio.h>
using namespace std;
int arr[3][2];
int CCW()
{
	int t1 = 0, t2 = 0;
	for (int i = 0; i < 3; i++)
	{
		t1 += arr[i][0] * arr[(i + 1) % 3][1];
		t2 += arr[i][1] * arr[(i + 1) % 3][0];
	}
	return t1 - t2;
}
int main()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 2; j++)
			scanf("%d", &arr[i][j]);
	int result = CCW();
	int ans = 0;
	if (result < 0) ans--;
	if (result > 0) ans++;
	printf("%d", ans);
	return 0;
}