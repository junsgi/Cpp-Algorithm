def solution(score):
    answer = [1] * len(score)
    for i in range(len(score)):
        for j in range(len(score)):
            if i == j: continue
            if sum(score[i]) / 2 < sum(score[j]) / 2:
                answer[i] += 1
    return answer