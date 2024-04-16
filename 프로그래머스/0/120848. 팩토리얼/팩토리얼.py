def solution(n):
    f = lambda x : x * f(x - 1) if x else 1
    for i in range(1, 10):
        if n < f(i):
            return i - 1
    return 10
