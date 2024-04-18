def solution(s):
    answer = ''
    check = [0] * 27
    for i in s:
        check[ord(i) - 97] += 1
    for i in range(27):
        if check[i] == 1: answer += chr(i + 97)
    return answer