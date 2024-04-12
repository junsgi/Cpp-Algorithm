#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int cmp(vector<int> x, vector<int> y)
{
    return x[0] < y[0] || x[0] == y[0] && x[1] < y[1];
}
int solution(vector<vector<int>> routes) {
    for (auto i : routes)
    {
        int t1 = i[0], t2 = i[1];
        i[0] = min(t1, t2);
        i[1] = max(t1, t2);
    }
    sort(routes.begin(), routes.end(), cmp);
    int st = routes[0][0], ed = routes[0][1];
    int ans = 1;
    for(int i = 1; i < (int)routes.size() ; i++)
    {
        if (ed < routes[i][0])
        {
            ans++;
            ed = routes[i][1];
        }
        ed = min(ed, routes[i][1]);
    }
    return ans;
}
