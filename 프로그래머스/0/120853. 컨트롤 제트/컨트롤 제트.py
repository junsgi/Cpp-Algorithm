def solution(s):
    answer = 0
    s = s.split()
    for i in range(len(s)):
        if s[i].isdigit() or s[i] != "Z": answer += int(s[i])
        elif s[i] == "Z": answer -= int(s[i - 1])
    return answer