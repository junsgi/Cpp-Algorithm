
from collections import deque
dire = tuple(((-1, 0), (1, 0), (0, -1), (0, 1)))
def BFS(x, y, cnt, visit, MAP, ck):
    que = deque()
    que.append((x, y))
    visit[x][y] = cnt
    while que:
        ax, ay = que.popleft()
        
        for a, b in dire:
            tx, ty = ax + a, ay + b
            if not (0 <= tx < len(MAP) and 0 <= ty < len(MAP[0])) : continue
            if visit[tx][ty] or abs(MAP[ax][ay] - MAP[tx][ty]) > ck: continue
            visit[tx][ty] = cnt
            que.append((tx, ty))

def find(node, freq):
    if node == freq[node]:
        return node
    freq[node] = find(freq[node], freq)
    return freq[node]
def union(x, y, freq, answer, value):
    fx, fy = find(x, freq), find(y, freq)
    if fx == fy: return
    if fx < fy:
        freq[fy] = fx
        answer[fx] += answer[fy] + value
    else:
        freq[fx] = fy
        answer[fy] += answer[fx] + value
def solution(land, height):
    N, M = len(land), len(land[0])
    visit = [[0] * M for i in range(N)]
    cnt = 1
    MAX = 0x7fffffff
    for i in range(N):
        for j in range(M):
            if not visit[i][j]:
                BFS(i, j, cnt, visit, land, height)
                cnt += 1
    graph = {i : {} for i in range(1, cnt)}
    for i in range(N):
        for j in range(M):
            for a, b in dire:
                tx, ty = i + a, j + b
                if not (0 <= tx < N and 0 <= ty < M) : continue
                if visit[i][j] == visit[tx][ty] : continue
                value = abs(land[i][j] - land[tx][ty])
                if visit[tx][ty] not in graph[visit[i][j]]:
                    graph[visit[i][j]][visit[tx][ty]] = MAX
                if visit[i][j] not in graph[visit[tx][ty]]:
                    graph[visit[tx][ty]][visit[i][j]] = MAX
                    
                graph[visit[i][j]][visit[tx][ty]] = min(value, graph[visit[i][j]][visit[tx][ty]])
                graph[visit[tx][ty]][visit[i][j]] = min(value, graph[visit[tx][ty]][visit[i][j]])
    for i in graph.keys():
        graph[i] = graph[i].items()
    result = [] 
    freq = [i for i in range(cnt)]
    answer = [0] * cnt
    for i, j in sorted(graph.items()):
        for ed, value in j:
            result.append((i, ed, value))
    result.sort(key = lambda x : x[2])
    for i in range(0, len(result)):
        st, ed, value = result[i]
        union(st, ed, freq, answer, value)

    return answer[1]