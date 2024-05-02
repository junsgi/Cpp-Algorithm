import sys
sys.setrecursionlimit(50_001)
class Tree:
    def __init__(s, value):
        s.value = value
        s.left = None
        s.right = None
group = 0

def getTree(num, links):
    LEN = len(num)
    parent = [-1] * LEN
    nodes = [Tree(i) for i in num]
    for i in range(LEN):
        if links[i][0] != -1:
            nodes[i].left = nodes[links[i][0]]
            parent[links[i][0]] = i
        if links[i][1] != -1:
            nodes[i].right = nodes[links[i][1]]
            parent[links[i][1]] = i
    for i in range(LEN):
        if parent[i] == -1:
            return nodes[i]
def post(node, k, mid):
    global group
    if group > k : return 0
    
    left = post(node.left, k, mid) if node.left else 0
    right = post(node.right, k, mid) if node.right else 0
    if min(left, right) + node.value > mid :
        group += 2
        return node.value
    
    if left + right + node.value <= mid:
        return left + right + node.value
    else:
        if left < right:
            if left + node.value <= mid:
                group += 1
                return left + node.value
            else:
                return node.value
        else:
            if right + node.value <= mid:
                group += 1
                return right + node.value
            else:
                return node.value
    
    
    
def solution(k, num, links):
    global group
    if k == len(num) - 1: return max(num)
    answer = -1
    root = getTree(num, links)
    le, ri = max(num), 10 ** 8
    mid = 0
        
    while le <= ri:
        mid = (le + ri) // 2
        group = 1
        post(root, k, mid)
        if group <= k:
            answer = mid
            ri = mid - 1
        else:
            le = mid + 1
    return answer
