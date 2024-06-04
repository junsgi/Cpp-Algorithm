import sys
input = sys.stdin.readline
n = int(input().rstrip())
for _ in range(n):
    LEN = int(input().rstrip())
    arr1 = list(map(int, input().rstrip().split()))
    arr2 = list(map(int, input().rstrip().split()))
    for i in range(1, LEN):
        arr1[i] = max(arr1[i - 1], arr1[i] + arr2[i - 1])
        arr2[i] = max(arr2[i - 1], arr2[i] + arr1[i - 1])
    print(max(arr1[-1], arr2[-1]))