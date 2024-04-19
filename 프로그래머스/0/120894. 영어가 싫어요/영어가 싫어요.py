def solution(numbers):
    lst = ["zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]
    check = {lst[i] : str(i) for i in range(10)}
    answer = ""
    temp = ""
    for n in numbers:
        temp += n
        if temp in lst:
            answer += check[temp]
            temp = ""
    return int(answer)