def solution(lines):
    answer = 0
    sweeping = []
    nums = []
    for line in lines:
        num = 0
        YMD, HMSMi, end = line.split(" ")
        
        end = end[:-1].split(".")
        if len(end) == 2 : end = int(end[0]) * 1000 + int(end[1])
        else : end = int(end[0]) * 1000
        H = HMSMi.split(":")
        H.extend(H.pop().split("."))
        H = list(map(int, H))
        
        num += H[3]
        num += H[2] * 1000
        num += H[1] * 1000 * 60
        num += H[0] * 1000 * 60 * 60
        sweeping.append([num - end, 1])
        sweeping.append([num + 999, -1])
    sweeping.sort()
    cnt = 0
    for st, ed in sweeping:
        cnt += ed
        answer = max(answer, cnt)
    return answer

# solution(["2016-09-15 03:10:33.020 0.011s"])
# 0000,00,00,00,00,00,000
# 00,000,000,000,000,000
# compress value, accumulated sum