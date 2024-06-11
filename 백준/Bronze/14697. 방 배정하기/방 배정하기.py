import sys
input = sys.stdin.readline
a, b, c, n = map(int, input().strip().split())
flag = 0
for i in range(n // a + 1):
    for j in range(n // b + 1):
        for k in range(n // c + 2):
            if (i * a) + (j * b) + (k * c) == n:
                flag = 1
            if flag : break
        if flag : break
    if flag : break
print(flag)