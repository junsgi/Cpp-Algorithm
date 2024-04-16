#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
// 가장 멀리 있는 곳에서 필수로 이동해야하는 거리 동안
// 얼마나 배달 할 수 있는지
long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups)
{
    long long answer = 0;
    long long D = 0, P = 0, CNT = 0;
    int i = n - 1;
    int cntD = 0, cntP = 0;
    while (i >= 0 && !(deliveries[i] || pickups[i])) { i--; n--; }

    for (; i >= 0; i--, n--)
    {
        if (P)
        {
            if (P >= pickups[i])
            {
                P -= pickups[i];
                pickups[i] = 0;
            }
            else
            {
                pickups[i] -= P;
                P = 0;
            }
        }
        if (pickups[i])
        {
            CNT = pickups[i] / cap;
            if (pickups[i] % cap) CNT++;
            answer += n * CNT * 2;

            D += cap * CNT;
            P += cap * CNT - pickups[i];
        }

        if (D)
        {
            if (D >= deliveries[i])
            {
                D -= deliveries[i];
                deliveries[i] = 0;
            }
            else
            {
                deliveries[i] -= D;
                D = 0;
            }
        }

        if (deliveries[i])
        {
            CNT = deliveries[i] / cap;
            if (deliveries[i] % cap) CNT++;
            answer += n * CNT * 2;

            P += cap * CNT;
            D += cap * CNT - deliveries[i];
        }
    }
    return answer;
}