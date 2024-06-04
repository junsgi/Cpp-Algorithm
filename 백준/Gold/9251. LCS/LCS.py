import sys
input = sys.stdin.readline
s1 = input().rstrip()
s2 = input().rstrip()
LEN1 = len(s1)
LEN2 = len(s2)
DP = [[0] * (LEN2 + 1) for _ in range(LEN1 + 1)]
for i in range(1, LEN1 + 1):
    for j in range(1, LEN2 + 1):
        if s1[i - 1] == s2[j - 1]:
            DP[i][j] = DP[i - 1][j - 1] + 1
        else:
            DP[i][j] = max(DP[i - 1][j], DP[i][j - 1])
print(DP[LEN1][LEN2])