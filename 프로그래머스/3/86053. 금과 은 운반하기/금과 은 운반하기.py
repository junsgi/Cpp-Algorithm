def solution(a, b, g, s, w, t):
    LEN = len(g)
    left, right = 1, 400_000_000_000_000
    mid = 0
    while left <= right: # 금 + 은 최대 20억, 이동 시간 100_000, 최대 중량 1
        mid = (left + right) // 2
        G, S, T = 0, 0, 0
        for i in range(LEN):
            gold, silver, weight, time = g[i], s[i], w[i], t[i]
            cnt = mid // (time * 2)
            if mid % (time * 2)>= time: cnt += 1
            
            res = min(weight * cnt, gold + silver)
            T += res
            G += min(res, gold)
            S += min(res, silver)
            
        if T >= a + b and G >= a and S >= b:
            right = mid - 1
        else :
            left = mid + 1
    return left