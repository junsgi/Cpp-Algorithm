def solution(dots):
    answer = 0
    dots.sort()
    print(dots)
    return abs(dots[1][1] - dots[0][1]) * abs(dots[2][0] - dots[0][0])