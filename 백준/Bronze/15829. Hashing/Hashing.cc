#pragma warning(disable:4996)
#include <stdio.h>
using namespace std;
int  M = 1234567891, n;
char arr[55];
long long ans, r = 1;
int main()
{
    scanf("%d", &n);
    scanf("%s", arr);
    for (int i = 0; i < n; i++)
    {
        ans += r * (arr[i] - 96) % M;
        r = r * 31 % M;
    }
    printf("%lld", ans % M);
    return 0;
}