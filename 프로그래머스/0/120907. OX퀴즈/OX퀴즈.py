def solution(quiz):
    answer = []
    for q in quiz:
        poly, ans = q.split(" = ")
        res1 = eval(poly)
        res2 = int(ans)
        if res1 == res2 : answer.append("O")
        else: answer.append("X")
    return answer