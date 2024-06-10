import sys
input = sys.stdin.readline
n = int(input().strip())
arr = list(map(int, input().strip().split()))
DP = [0] * (n + 1)
DP[1] = arr[0]
for i in range(2, n + 1):
    DP[i] = arr[i - 1]
    for j in range(i):
        DP[i] = max(DP[i], DP[i - j] + DP[j])
print(DP[-1])