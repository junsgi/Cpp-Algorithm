#pragma warning(disable:4996)
#include<stdio.h>
#include<vector>
#define M 50001
using namespace std;
int n, ans;
char word[200'010];
vector<int> Hash[M];
bool cmp(int v, int w, int mid)
{
	for (int i = 0; i < mid; i++)
	{
		if (word[v + i] != word[w + i])
			return false;
	}
	return true;
}

int chk(int mid)
{
	for (int i = 0; i < M; i++) Hash[i].clear();
	int num = 0, r = 31, k = 1;

	for (int i = 1; i <= n; i++)
	{
		if (i < mid) k = k * r % M;
		if (i > mid)
		{
			// i가 mid보다 커졌다면 슬라이딩 윈도우의 위치를 오른쪽으로 한 칸 옮긴다.
			num -= ((word[i - mid] - 96) * k) % M; 

			// 음수가 되었다면 양수로 바꾼다.
			num = (num + M) % M;
		}


		// mid 길이 만큼의 Hash Key값 생성
		num = (num * r) % M;
		num = (num + (word[i] - 96)) % M;

		if (i >= mid)
		{
			for (int j = 0; j < (int)Hash[num].size(); j++)
				if (cmp(Hash[num][j], i - mid + 1, mid))
					return true;

			Hash[num].push_back(i - mid + 1);
		}
	}
	return false;
}
int main()
{
	scanf("%d", &n);
	scanf("%s", &word[1]);
	int le = 1, ri = n, mid = 0;
	while (le <= ri)
	{
		mid = (le + ri) / 2;
		if (chk(mid)) // mid 길이의 반복 부분 문자열이 존재한다면 길이를 늘린다.
		{
			ans = mid;
			le = mid + 1;
		}
		else
			ri = mid - 1;
	}
	printf("%d", ans);
	return 0;
}