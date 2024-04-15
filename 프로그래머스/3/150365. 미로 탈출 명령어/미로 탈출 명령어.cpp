
#include <algorithm>
#include <queue>
#include <string>
#include <iostream>
using namespace std;
struct temp {
    int x, y; string path;
};
int dire[4][2] = { {1, 0}, {0, -1}, {0, 1}, {-1, 0} };
int check[51][51];
int sCount[4];
string c = "dlru";
string BFS(int x, int y, int ex, int ey, int n, int m)
{
    queue<temp> que = {};
    que.push({ x, y, ""});
    check[x][y] = 1;

    while (!que.empty())
    {
        int cx = que.front().x;
        int cy = que.front().y;
        string path = que.front().path;
        que.pop();
        if (cx == ex && cy == ey)
            return path;

        for (int i = 0; i < 4; i++)
        {
            int tx = cx + dire[i][0], ty = cy + dire[i][1];
            string tPath = path + c[i];
            if (!(1 <= tx && tx <= n && 1 <= ty && ty <= m)) continue;
            if (check[tx][ty]) continue;
            check[tx][ty] = check[cx][cy] + 1;
            que.push({ tx, ty, tPath });
        }
    }
    return "";
}

void getPath(int x, int y, int n, int m, int k)
{
    int dCnt = min(n - x, k / 2);
    
    for(int i = 0 ; i < dCnt ; i++) // 내려갈 수 있는 개수
    {
        sCount[0]++;
        sCount[3]++; // 자리 복구
        k -= 2;
        
    }
    while (k) // 왼쪽으로 갈 수 있는 개수
    {
        sCount[1]++;
        sCount[2]++; // 자리 복구
        k -= 2;
    }
}
string getAns(int y)
{
    string ans = "";
    // 내려갈 수 있는 만큼 내려간다.
    for(int i = 0 ; i < sCount[0] ; i++) ans += 'd';
    int cnt = sCount[1] - sCount[2];
    if (cnt > 0) // 왼쪽으로 더 갈 수 있다면
    {
        for(int i = 0 ; i < cnt ; i++) ans += 'l';
        y -= cnt;
    }
    sCount[1] -= max(0, cnt);
    
    
    while (sCount[1] > 0 && y > 1) // 왼쪽으로 범위를 벗어나지 않으면서 채울만큼 채운다.
    {
        ans += "l";
        y--;
        sCount[1]--;
    }
    
    
    while (sCount[1]) // 왼쪽 끝에 도착했다면 와리가리
    {
        ans += "rl";
        sCount[1]--;
        sCount[2]--;
    }
    while (sCount[2]--) ans += "r";
    while (sCount[3]--) ans += "u";
    
    return ans;
}
string solution(int n, int m, int x, int y, int r, int c, int k) {
    int check = abs(r - x) + abs(c - y);
    if (check > k || abs(check - k) % 2) return "impossible";
    
    string path = BFS(x, y, r, c, n, m);
    for(int i = 0 ; i < (int)path.length() ; i++)
    {
        if (path[i] == 'u') sCount[3]++;
        else if (path[i] == 'd') sCount[0]++;
        else if (path[i] == 'l') sCount[1]++;
        else sCount[2]++;
    }
    
    int tx, ty;
    if (x < r)
    {
        tx = r; ty = c;
    }else
    {
        tx = x; ty = y;
    }
    
    int cnt = k - (int)path.length();
    getPath(tx, ty, n, m, cnt);
    return getAns(y);
}