#include<stdio.h>
int n;
bool isPri(int num)
{
	for(int i = 2 ; i * i <= num ; i++)
	{
		if (num % i == 0) return false;
	}
	return true;
}
bool isPalin(int num)
{
	int arr[10] = {0,};
	int len = 0;
	while (num)
	{
		arr[len++] = num % 10;
		num/=10;
	}
	for(int i = 0 ; i < len / 2 ; i++)
	{
		if (arr[i] != arr[len - i - 1])
			return false;
	}
	return true;
}
int main()
{
	scanf("%d", &n);
	if (n == 1)n++;
	while(1)
	{
		if (isPri(n) && isPalin(n)) 
		{
			printf("%d ", n);
			break;
		}
		n++;
	}
	return 0;
}