def solution(n):
    answer = []
    p = [2]
    for i in range(3, n + 1, 2):
        for j in range(2, int(i ** 0.5) + 1):
            if i % j == 0:
                break
        else:
            p.append(i)
    for i in p:
        if i > n: break
        if n % i == 0: answer.append(i)
    return answer