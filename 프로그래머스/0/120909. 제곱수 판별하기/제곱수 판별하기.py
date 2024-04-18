def solution(n):
    check = set()
    i = 1
    while i * i <= 1_000_000:
        check.add(i * i)
        i += 1
    if n in check: return 1
    return 2