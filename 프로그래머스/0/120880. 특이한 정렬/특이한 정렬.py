def solution(numlist, n):
    idx = sorted(list(map(lambda x : [abs(x - n), x - n <= 0], numlist)), key = lambda x : (x[0], x[1]))
    answer = list(map(lambda x : n - x[0] if x[1] else n + x[0], idx))
    return answer