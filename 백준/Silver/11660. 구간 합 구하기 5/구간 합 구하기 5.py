import sys
input = sys.stdin.readline
n, m = map(int, input().split())
arr = tuple(tuple(map(int, input().split())) for _ in range(n))
DP = [[0] * (n + 1) for _ in range(n + 1)]
for i in range(1, n + 1):
    for j in range(1, n + 1):
        DP[i][j] = DP[i][j - 1] + arr[i - 1][j - 1]
for j in range(1, n + 1):
    for i in range(1, n + 1):
        DP[i][j] += DP[i - 1][j]
for _ in range(m):
    x1, y1, x2, y2 = map(int, input().split())
    print(DP[x2][y2] - DP[x2][y1 - 1] - DP[x1 - 1][y2] + DP[x1 - 1][y1 - 1])