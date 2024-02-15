import sys
input = sys.stdin.readline
sys.setrecursionlimit(60000)
def MIN(a, b):
    return a if a[1] < b[1] else b
def insert(index, value):
    global idx
    temp = idx + index - 1
    seg[temp] = [index, value]
    temp //= 2
    while temp > 0:
        seg[temp] = MIN(seg[temp * 2], seg[temp * 2 + 1])
        temp //= 2
def query(left, right, idx, st, ed):
    global MAX
    if ed < left or right < st : return [MAX, MAX]
    if st <= left and right <= ed : return seg[idx]
    mid = (left + right) // 2
    return MIN(query(left, mid, idx * 2, st, ed), query(mid + 1, right, idx * 2 + 1, st, ed))

def 분할(left, right):
    global n, ans, idx
    if left > right : return
    temp = query(1, idx, 1, left, right)
    ans = max(ans, temp[1] * (right - left + 1))

    분할(left, temp[0] - 1)
    분할(temp[0] + 1, right)
n = int(input())
MAX = 0x7fffffff
seg = [[0, MAX] for _ in range(1 << 18)]

idx = 1
ans = 0
while idx <= n :
    idx *= 2
for i in range(1, n + 1):
    m = int(input())
    insert(i, m)
check = 1
cnt = 1
분할(1, n)
print(ans)