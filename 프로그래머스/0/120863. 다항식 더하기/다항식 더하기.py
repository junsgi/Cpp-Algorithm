def solution(polynomial):
    answer = ''
    x = 0
    n = 0
    for i in polynomial.split(" + "):
        if i[-1] == "x" : x += int(i[:-1] if i[:-1] else 1)
        else : n += int(i)
    if x :
        if x > 1: answer += f"{x}x"
        else : answer += "x"
    if answer and n : answer += f" + {n}"
    elif not answer : answer = f"{n}"
    return answer

