#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
#include<stack>
#define M 0x7fffffff
using namespace std;
int arr[100'001], n, check[100'001], cnt[100'001], dist[100'001];
stack<int> left, right;
int main()
{
	scanf("%d", &n);
	fill(dist + 1, dist + n + 1, M);
	fill(check + 1, check + n + 1, M);
	for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);

	for (int i = 1; i <= n; i++)
	{
		while (!left.empty() && arr[i] >= arr[left.top()]) left.pop(); // 현재 높이보다 낮은 건물은 모두 pop
		cnt[i] += (int)left.size(); // 스택의 길이 == 현재 위치 기준 왼쪽 방향으로 바라봤을 때 볼 수 있는 건물의 개수
		if (!left.empty() && dist[i] > abs(i - left.top()) || !left.empty() && dist[i] == abs(i - left.top()) && check[i] > left.top())
		{
			check[i] = left.top();
			dist[i] = abs(i - left.top());
		}
		left.push(i);
	}

	for (int i = n; i > 0; i--)
	{
		while (!right.empty() && arr[i] >= arr[right.top()]) right.pop();
		cnt[i] += (int)right.size();
		if (!right.empty() && dist[i] > abs(i - right.top()) || !right.empty() && dist[i] == abs(i - right.top()) && check[i] > right.top())
		{
			check[i] = right.top();
			dist[i] = abs(i - right.top());
		}
		right.push(i);
	}
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", cnt[i]);
		if (cnt[i]) printf("%d", check[i]);
		printf("\n");
	}
	return 0;
}
