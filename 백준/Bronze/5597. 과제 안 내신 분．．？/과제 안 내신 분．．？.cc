#pragma warning(disable:4996)
#include <stdio.h>
long long a = 1,t;int main(){a<<=31;for(int i=0;i<28;i++){scanf("%lld",&t);a|=(long long)1<<t;}t=0;while(a){if(t&&!(a%2))printf("%lld\n",t);a/=2;t++;}return 0;}