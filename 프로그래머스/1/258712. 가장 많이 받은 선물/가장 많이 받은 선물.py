def solution(friends, gifts):
    LEN = len(friends)
    graph = [[0] * (LEN + 1) for _ in range(LEN + 1)]
    e = [0] * (LEN + 1)
    answer = [0] * (LEN + 1)
    dict = {}
    for f in range(LEN):
        dict[friends[f]] = f + 1
    for w in gifts:
        st, ed = w.split()
        graph[dict[st]][dict[ed]] += 1
    for i in range(1, LEN + 1):
        e[i] = sum(graph[i]) - sum(map(lambda x : x[i], graph))
    
    for i in range(1, LEN):
        for j in range(i + 1, LEN + 1):
            if graph[i][j] + graph[j][i] != 0 and graph[i][j] != graph[j][i]:
                if graph[i][j] < graph[j][i]:
                    answer[j] += 1
                else:
                    answer[i] += 1
            elif e[i] < e[j]:
                answer[j] += 1
            elif e[j] < e[i]:
                answer[i] += 1
    return max(answer)