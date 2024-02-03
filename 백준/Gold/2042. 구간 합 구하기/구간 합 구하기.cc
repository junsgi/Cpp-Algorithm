#pragma warning(disable:4996)
#include<stdio.h>
#define MAX 1 << 21
using namespace std;
int n, m, k, st;
long long arr[MAX], a, b, c;
int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (st = 1; st <= n; st *= 2);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &arr[i + st]);
		for (int j = (i + st) / 2; j > 1; j /= 2)
			arr[j] = arr[j * 2] + arr[j * 2 + 1];
	}
	for (int i = 1; i <= m + k; i++)
	{
		scanf("%lld%lld%lld", &a, &b, &c);
		if (a == 1) // 바꾼다
		{
			arr[st + b - 1] = c;
			for (int j = (st + b - 1) / 2; j > 1; j /= 2)
				arr[j] = arr[j * 2] + arr[j * 2 + 1];
		}
		else // 출력한다.
		{
			b = b + st - 1;
			c = c + st - 1;
			long long result = 0;
			// 왼쪽 포인터가 홀수면 더하고 이동, 짝수면 그냥 이동
			// 오른쪽 포인터가 홀수면 그냥 이동, 짝수면 더하고 이동

			while (1)
			{
				if (b % 2 == 1)
					result += arr[b++];
				b /= 2;
				if (c % 2 == 0)
					result += arr[c--];
				c /= 2;
				if (b == c) result += arr[b];
				if (b >= c) break;
			}
			printf("%lld\n", result);
		}
	}
	return 0;
}