def solution(sides):
    answer = 0
    MIN = min(sides)
    MAX = max(sides)
    for i in range(1, MAX + 1):
        if MAX < MIN + i: answer += 1
    MAX += 1
    while MAX < sum(sides):
        answer += 1
        MAX += 1
    return answer