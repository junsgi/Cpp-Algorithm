def solution(a, b):
    answer = 0
    f = lambda x, y : f(y, x % y) if y else x
    res = f(a, b)
    a //= res
    b //= res
    if b <= 2: return 1
    for i in range(2, max(a, b) + 1):
        if i % 2 != 0 and i % 5 != 0 and b % i == 0:
            return 2
    return 1
    