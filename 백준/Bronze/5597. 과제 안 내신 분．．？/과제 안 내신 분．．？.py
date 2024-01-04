tmp = 1
tmp |= 1 << 31
for _ in range(28):
    t = int(input())
    tmp |= 1 << t
t = 0
while tmp:
    if tmp % 2 == 0: print(t)
    tmp //= 2
    t += 1