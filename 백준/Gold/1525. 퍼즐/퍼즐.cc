#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#define M 100'009
using namespace std;
struct temp {
	char* map;
	int z;
	int depth;
}t;
char graph[10];
char result[10] = "123456780";
int dire[2][4] = { {-1, 1, 0, 0}, {0, 0, -1, 1} };
int z;
long long K;
vector<char*> HashTable[M];
queue<temp> que;
int min(int a, int b) { return a > b ? b : a; }
long long getKey(char map[])
{
	long long result = 0, r = 1;
	for (int i = 0; i < 9; i++)
	{
		result = (result + (map[i] - '0') * r) % M;
		r = r * 31 % M;
	}
	return result % M;
}
bool check(long long key, char map[])
{
	for (int i = 0; i < (int)HashTable[key].size(); i++)
	{
		if (!strcmp(map, result))
			return true;
	}
	return false;
}
int BFS()
{
	que.push({ graph, z, 0 });
	HashTable[getKey(graph)].push_back(graph);

	while (!que.empty())
	{
		t = que.front();
		que.pop();
		char* map = t.map;
		int zero = t.z;
		int zx = zero / 3;
		int zy = zero % 3;
		int depth = t.depth;
		if (!strcmp(map, result))
			return depth;

		for (int i = 0; i < 4; i++)
		{
			int tx = zx + dire[0][i];
			int ty = zy + dire[1][i];
			int tz = tx * 3 + ty;
			if (!(0 <= tx && tx < 3)) continue;
			if (!(0 <= ty && ty < 3)) continue;
			char* copy = strdup(map);
			copy[zero] = copy[tz];
			copy[tz] = '0';
			if (!strcmp(copy, result))
				return depth + 1;

			long long tKey = getKey(copy);
			int swi = 0;
			for (int j = 0; j < (int)HashTable[tKey].size(); j++)
			{
				if (!strcmp(HashTable[tKey][j], copy))
				{
					swi = 1;
					break;
				}
			}
			if (swi) continue;
			
			HashTable[tKey].push_back(copy);
			que.push({ copy, tz, depth + 1 });
		}
	}
	return -1;
}
int main()
{
	K = getKey(result);
	HashTable[K].push_back(result);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			scanf(" %c", &graph[i * 3 + j]);
			if (graph[i * 3 + j] == '0')
				z = i * 3 + j;
		}
	}
	
	printf("%d", BFS());
	return 0;
}
