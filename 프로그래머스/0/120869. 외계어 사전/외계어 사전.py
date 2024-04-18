def solution(spell, dic):
    answer = 0
    words = []
    check = [0] * len(spell)
    def make(depth, string):
        if depth == len(spell):
            words.append(string)
            return
        for i in range(len(spell)):
            if check[i]: continue;
            check[i] = 1
            make(depth + 1, string + spell[i])
            check[i] = 0
    make(0, "")
    for w in words:
        for d in dic:
            if w in d: return 1
    return 2