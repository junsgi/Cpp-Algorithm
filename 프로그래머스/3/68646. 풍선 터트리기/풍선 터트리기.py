def solution(a):
    answer = len(a)
    stk = []
    for i in a:
        while stk and i < stk[-1]:
            stk.pop()
            if stk: answer -= 1
        stk.append(i)
    return answer