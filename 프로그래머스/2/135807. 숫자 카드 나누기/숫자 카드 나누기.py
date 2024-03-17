def gcd(x, y):
    if not y: return x
    return gcd(y, x % y)
def solution(arrayA, arrayB):
    answer = 0
    LEN = len(arrayA)
    if LEN == 1:
        A, B = arrayA[0] % arrayB[0], arrayB[0] % arrayA[0]
        if not (A or B): answer = 0
        else: answer = max(arrayA[0], arrayB[0])
    else:
        A, B = gcd(arrayA[0], arrayA[1]), gcd(arrayB[0], arrayB[1])
        for i in range(2, LEN):
            A, B = gcd(A, arrayA[i]), gcd(B, arrayB[i])
        resAA, resAB = sum(map(lambda x : x % A == 0, arrayA)), sum(map(lambda x : x % B == 0, arrayA))
        resBB, resBA = sum(map(lambda x : x % B == 0, arrayB)), sum(map(lambda x : x % A == 0, arrayB))
        if resAA * resAB == 0 or resBB * resBA == 0: answer = max(A, B)

    return answer