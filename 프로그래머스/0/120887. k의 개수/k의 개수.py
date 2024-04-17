def solution(i, j, k):
    answer = 0
    for i in range(i, j + 1):
        
        while i :
            if i % 10 == k : answer += 1
            i //= 10
    return answer