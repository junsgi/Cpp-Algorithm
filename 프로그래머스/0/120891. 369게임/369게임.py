def solution(order):
    answer = 0
    while order:
        if order % 10 and order % 10 % 3 == 0: answer += 1
        order //= 10
    return answer