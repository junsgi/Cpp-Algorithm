def solution(num, k):
    answer = 0
    cnt = 0
    flag = False
    while num:
        cnt += 1
        if num % 10 == k:
            flag = True
            answer = cnt
        num //= 10
    if flag: return cnt - answer + 1
    return -1