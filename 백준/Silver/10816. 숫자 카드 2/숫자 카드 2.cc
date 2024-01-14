#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#define M 50'009
using namespace std;
int a, b, s;
struct temp 
{
	int key, value;
};
vector<temp> HashTable[M];
int Key(int t) { return t % M; }

int main()
{
	scanf("%d", &a);
	for (int i = 0; i < a; i++)
	{
		scanf("%d", &b);
		s = 0;
		b += 10'000'000;
		int key = Key(b);
		for (int j = 0; j < (int)HashTable[key].size(); j++)
		{
			if (HashTable[key][j].key == b)
			{
				HashTable[key][j].value++;
				s = 1;
				break;
			}
		}
		if (s == 0)
			HashTable[key].push_back({b, 1});
	}
	
	scanf("%d", &a);
	for (int i = 0; i < a; i++)
	{
		scanf("%d", &b);
		s = 0;
		b += 10'000'000;
		int key = Key(b);
		for (int j = 0; j < (int)HashTable[key].size(); j++) 
		{
			if (HashTable[key][j].key == b)
			{
				s = 1;
				printf("%d ", HashTable[key][j].value);
				break;
			}
		}
		if (s == 0)
			printf("0 ");
	}
	return 0;
}
