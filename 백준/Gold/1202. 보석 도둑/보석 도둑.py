#https://www.acmicpc.net/submit/1202
from heapq import heappush, heappop
n, k = map(int, input().split())
jewelry = [list(map(int, input().split())) for _ in range(n)]
bag = [int(input()) for _ in range(k)]
jewelry.sort(reverse=True)
bag.sort()
heap = []
ans = 0
for b in bag:
    while jewelry and jewelry[-1][0] <= b:
        heappush(heap, -jewelry.pop()[1])
    if heap:
        ans += -heappop(heap)
print(ans)