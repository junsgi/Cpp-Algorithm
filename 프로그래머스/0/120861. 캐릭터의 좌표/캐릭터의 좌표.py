def solution(keyinput, board):
    loc = [board[0] // 2, board[1] // 2]
    answer = [0, 0]
    check = {
        "left" : (-1, 0),
        "right" : (1, 0),
        "up" : (0, 1),
        "down" : (0, -1)
    }
    for c in keyinput:
        if not (0 <= loc[0] + check[c][0] < board[0] and 
           0 <= loc[1] + check[c][1] < board[1]): continue
        answer[0] += check[c][0]
        answer[1] += check[c][1]
        loc[0] += check[c][0]
        loc[1] += check[c][1]
    return answer