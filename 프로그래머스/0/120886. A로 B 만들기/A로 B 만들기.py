def solution(before, after):
    answer = 0
    check = {}
    before = sorted(list(before))
    after = sorted(list(after))
    for i in range(len(before)):
        if before[i] != after[i]:
            return 0
    
    return 1