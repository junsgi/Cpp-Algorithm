#include<stdio.h>
#include<algorithm>
#include<vector>
#define M 26
using namespace std;

vector<int> T[M];
int n;

void preorder(int k)
{
	printf("%c",k+'A');
	if(T[k][0]!=-1) preorder(T[k][0]);
	if(T[k][1]!=-1) preorder(T[k][1]);
}
void inorder(int k)
{
	if(T[k][0]!=-1) inorder(T[k][0]);
	printf("%c",k+'A');
	if(T[k][1]!=-1) inorder(T[k][1]);
}
void postorder(int k)
{
	if(T[k][0]!=-1) postorder(T[k][0]);
	if(T[k][1]!=-1) postorder(T[k][1]);
	printf("%c",k+'A');
}
int main()
{

	int i;
	char a,b,c;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf(" %c %c %c",&a,&b,&c);
		(b=='.') ? T[a-'A'].push_back(-1):T[a-'A'].push_back(b-'A');
		(c=='.') ? T[a-'A'].push_back(-1):T[a-'A'].push_back(c-'A');
	}
	preorder(0); //전위
	printf("\n");
	inorder(0);  //중위
	printf("\n");
	postorder(0);//후위
	return 0;
}