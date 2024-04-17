def solution(chicken):
    answer = 0
    cp = 0
    while chicken:
        answer += chicken // 10
        cp += chicken % 10
        chicken //= 10
    while cp >= 10:
        t = cp // 10
        answer += t
        cp %= 10
        cp += t
    return answer