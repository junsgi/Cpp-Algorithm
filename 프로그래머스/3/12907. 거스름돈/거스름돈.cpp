#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n, vector<int> money) {
    int* DP = new int[100'001];
    DP[0] = 1;
    for(auto i : money)
        for(int j = i ; j <= n ; j++)
            DP[j] += DP[j - i];
    return DP[n];
}