from collections import deque, defaultdict
dire = tuple(((-1, 0), (1, 0), (0, -1), (0, 1)))
def BFS(i, j, graph, visit, flag, cnt):
    N, M = len(graph), len(graph[0])
    result = ["", "", "", ""]
    que = deque()
    que.append((i, j))
    visit[i][j] = cnt
    minX, minY = i, j
    maxX, maxY = i, j
    
    while que:
        x, y = que.popleft()
        for a, b in dire:
            tx, ty = x + a, y + b
            if not (0 <= tx < N and 0 <= ty < M):
                continue
            if graph[tx][ty] == abs(flag - 1) or visit[tx][ty] == cnt:
                continue
            minX, minY = min(minX, tx), min(minY, ty)
            maxX, maxY = max(maxX, tx), max(maxY, ty)
            visit[tx][ty] = cnt
            que.append((tx, ty))
    for i in range(minX, maxX + 1):
        for j in range(minY, maxY + 1):
            if visit[i][j] == cnt:
                result[0] += "1"
            else:
                result[0] += "0"
        result[0] += "."
        
    for j in range(maxY, minY - 1, -1):
        for i in range(minX, maxX + 1):
            if visit[i][j] == cnt:
                result[1] += "1"
            else:
                result[1] += "0"
        result[1] += "."
    
    result[2] = result[0][::-1]
    result[3] = result[1][::-1]
    result = list(map(lambda x : x.strip("."), result))
    return result

def solution(game_board, table):
    answer = 0
    N, M = len(table), len(table[0])
    board = tuple((game_board, table))
    visit = [[0] * M for _ in range(N)]
    blocks = []
    blanks = []
    check = defaultdict(int)
    cnt = 1
    for b in range(2):
        for i in range(N):
            for j in range(M):
                if board[b][i][j] != abs(b - 1) and not visit[i][j]:
                    res = BFS(i, j, board[b], visit, b, cnt)
                    cnt += 1
                    if b == 0:
                        blanks.append(res)
                    else:
                        blocks.append(res)
        visit = [[0] * M for _ in range(N)]
    for b in blocks:
        for e in b:
            check[e] += 1
    for blankss in blanks:
        blk = ""
        for blank in blankss:
            if blank in check:
                blk = blank
                break
        
        if blk and check[blk] - 1 >= 0:
            answer += blk.count("1")
            for blank in blankss:
                check[blank] -= 1
        
    return answer
