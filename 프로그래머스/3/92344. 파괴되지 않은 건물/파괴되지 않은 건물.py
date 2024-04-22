"""
일차원 배열 [1, 2, 3, 4, 5, 6, 7]에서 0 ~ 4번의 값을 n만큼 빼고싶다면 (누적합 사용)
1. 0으로 채운 check배열 생성 (원래 길이보다 1 더 길어야함)
2. 빼고싶은 시작 지점에 -n, 끝 지점 + 1 인덱스에 n  => [-n, 0, 0, 0, 0, n, 0]
3. 누적합 => [-n, -n, -n, -n, -n, 0, 0]
4. 원본 배열과 check 배열의 값을 더한다.

예시
[1, 2, 3, 4, 5] 배열에서 0 ~ 2 값을 3 더하고, 1 ~ 4 값을 5 뺀다
1. [3, 0, 0, -3, 0, 0]
2. [3, -5, 0, -3, 0, 5]
3. 누적합 => [3, -2, -2, -5, -5, 0]
4. 각 인덱스에 맞게 더한다. => [4, 0, 1, -1, 0]
"""
def solution(board, skill):
    N = len(board)
    M = len(board[0])
    check = [[0] * (len(board[0]) + 1) for _ in range(len(board) + 1)]
    for s, rx, ry, cx, cy, value in skill:
        flag = 1 if s == 2 else -1
        check[rx][ry] += value * flag
        check[rx][cy + 1] += -value * flag
        check[cx + 1][cy + 1] += value * flag
        check[cx + 1][ry] += -value * flag
    for i in range(N + 1):
        for j in range(1, M + 1):
            check[i][j] += check[i][j - 1]
    for i in range(M + 1):
        for j in range(1, N + 1):
            check[j][i] += check[j - 1][i]
    answer = 0
    for i in range(N):
        for j in range(M):
            board[i][j] += check[i][j]
            if board[i][j] > 0: answer += 1
    return answer
