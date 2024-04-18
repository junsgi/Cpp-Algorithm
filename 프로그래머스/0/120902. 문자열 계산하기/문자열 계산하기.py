def solution(my_string):
    answer = 0
    stk = []
    operation = my_string[0]
    operator = 999
    if my_string[0] == '-' : operation = "-"
    for i in range(1, len(my_string)):
        if "0" <= my_string[i] <= '9': 
            operation += my_string[i]
        elif my_string[i] == '+':
            operator = 1
        elif my_string[i] == '-':
            if operator == 999 : operator = -1
            else : operation += my_string[i]
        else:
            if operation:
                stk.append(int(operation))
                operation = ""
            if operator != 999 and len(stk) == 2:
                num2 = stk.pop() * operator
                num1 = stk.pop()
                answer += num1 + num2
                stk.append(num1 + num2)
                operator = 999
    return stk.pop() + int(operation) * operator

