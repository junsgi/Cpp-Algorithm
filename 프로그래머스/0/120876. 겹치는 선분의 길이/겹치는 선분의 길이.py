def solution(lines):
    answer = 0
    visit = [0] * (201)
    for st, ed in lines:
        for i in range(st + 100, ed + 100):
            visit[i] += 1
    return len(tuple(i for i in visit if i >= 2))