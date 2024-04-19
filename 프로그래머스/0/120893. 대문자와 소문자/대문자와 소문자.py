def solution(my_string):
    answer = ''
    for i in my_string:
        if 'a' <= i: answer += chr(ord(i) - 32)
        else : answer += chr(ord(i) + 32)
    return answer