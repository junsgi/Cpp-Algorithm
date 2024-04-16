def solution(price):
    return int(price - price * 0.2 if price >= 500000 else price - price * 0.1 if price >= 300000 else price - price * 0.05 if price >= 100000 else price)