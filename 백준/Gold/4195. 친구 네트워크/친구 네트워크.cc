#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#include<vector>
#include <cstring>
#define N 205837
using namespace std;
vector<pair<char*, int>> HashTable[N]; // key, flag
int check[N];
int value[N];
int t, f, cnt = 1, tmp;
char f1[30], f2[30];

// 해시 값 반환
int getKey(char* name)
{
	unsigned long long result = 0, r = 1;
	for (int i = 0; name[i]; i++)
	{
		int value = name[i] - 64;
		result = (result + value * r) % N;
		r = r * 31 % N;
	}
	return (int)(result % N);
}

// 이름의 아이디 반환 (Union find에 활용)
int getId(int key, char* name)
{
	for (int i = 0; i < (int)HashTable[key].size(); i++)
	{
		if (!strcmp(HashTable[key][i].first, name))
			return HashTable[key][i].second;
	}

	// 새로운 메모리를 할당하고 name의 내용을 복사 후 temp에 대입
	char* temp = strdup(name);
	HashTable[key].push_back({temp, cnt++});
	return HashTable[key][(int)HashTable[key].size() - 1].second;
}

int find(int node)
{
	if (check[node] == node) return node;
	return check[node] = find(check[node]);
}
void Union(int x, int y)
{
	int fx = find(x);
	int fy = find(y);

	if (fx != fy) 
	{
		if (fx > fy)
			check[fy] = fx;
		else
			check[fx] = fy;
		value[fx] = value[fy] = value[fx] + value[fy]; // 서로 두 친구의 최상위 부모 노드에 친구 수 갱신
	}
	else value[fx] = value[fy] = value[fx];
}
int main()
{
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		scanf("%d", &f);
		fill(value, value + N, 1);
		cnt = 1;
		for (int j = 1; j < N; j++) check[j] = j;
		for (int j = 0; j < f; j++)
		{
			scanf("%s", f1);
			scanf("%s", f2);
			int f1Key = getKey(f1);
			int f1_id = getId(f1Key, f1);

			int f2Key = getKey(f2);
			int f2_id = getId(f2Key, f2);

			Union(f1_id, f2_id);
			printf("%d\n", value[find(f1_id)]);
		}
		for (int j = 0; j < N; j++)
			HashTable[j].clear();
	}

	return 0;
}