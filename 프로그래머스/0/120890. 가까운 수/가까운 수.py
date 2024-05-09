def solution(array, n):
    answer = 0x7fffffff
    c = 0x7fffffff
    for i in array:
        if abs(i - n) < c:
            c = abs(i - n)
            answer = i
        elif abs(i - n) == c:
            answer = min(answer, i)
    return answer