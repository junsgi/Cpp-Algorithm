#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int seg[1 << 21];

void insert(vector<int> a, int cnt) 
{
    for(int i = 0 ; i < (int)a.size() ; i++) 
    {
        int idx = cnt + i;
        seg[idx] = a[i];
        idx /= 2;
        while (idx) 
        {
            seg[idx] = min(seg[idx * 2], seg[idx * 2 + 1]);
            idx /= 2;
        }
    }
}
int query(int left, int right, int idx, int st, int ed) 
{
    if (ed < left || right < st) return 0x7fffffff;
    if (st <= left && right <= ed) return seg[idx];
    int mid = (left + right) / 2;
    return min(query(left, mid, idx * 2, st, ed), query(mid + 1, right, idx * 2 + 1, st, ed));
}
int solution(vector<int> a) 
{
    int answer = 0;
    int LEN = (int) a.size();
    if (LEN <= 2) return LEN;
    int MAX = 0x7fffffff;
    int cnt = 1;
    int c = 1;
    for(cnt = 1; cnt <= LEN ; cnt *= 2) c++;
    fill(seg, seg + cnt + 1, MAX);
    insert(a, cnt);
    answer = 2;
    for (int i = 1 ; i < LEN - 1 ; i++){
        if (query(1, cnt, 1, 1, i) > a[i] || query(1, cnt, 1, i + 2, LEN) > a[i])
            answer += 1;
    }
        
    return answer;
}