# https://school.programmers.co.kr/learn/courses/30/lessons/258711
from collections import defaultdict, deque
def BFS(node, graph, N):
    QUE = deque()
    QUE.append(node)
    res = [0, 1, 0, 0]
    freq = defaultdict(int)
    freq[node] = 1
    cnt = 0
    while QUE:
        x = QUE.popleft()
        if len(graph[x]) >= 2: return 3
        cnt += 1
        for tnode in graph[x]:
            freq[tnode] += 1
            res[freq[tnode]] += 1
            if freq[tnode] >= 2: continue
            QUE.append(tnode)
    if sum(res) == cnt:
        return 2
    else:
        return 1
    
def solution(edges):
    answer = [0, 0, 0, 0]
    graph = defaultdict(list)
    N = max(map(lambda x : max(x), edges))
    info = [0] * (N + 1)
    for st, ed in edges:
        graph[st].append(ed)
        info[ed] += 1
    node = 0
    t = 0
    for i in range(1, N + 1):
        if info[i] == 0 and len(graph[i]) > t:
            node = i
            t = len(graph[i])
    answer[0] = node
    for tnode in graph[node]:
        answer[BFS(tnode, graph, N)] += 1
    return answer