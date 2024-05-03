import sys
sys.setrecursionlimit(1_000_001)
class Node:
    def __init__(s):
        s.child = [None] * 26
        s.visit = 0
    
    @staticmethod
    def insert(value, node, depth):
        if depth == len(value): return
        idx = ord(value[depth]) - 97
        if not node.child[idx]:
            node.child[idx] = Node()
        node.child[idx].visit += 1
        Node.insert(value, node.child[idx], depth + 1)
        
    @staticmethod
    def getAnswer(node, value, depth):
        if depth == len(value):
            return depth
        if node.visit == 1:
            return depth
        idx = ord(value[depth]) - 97
        return Node.getAnswer(node.child[idx], value, depth + 1)

def solution(words):
    root = Node()
    answer = 0
    for i in words:
        Node.insert(i, root, 0)
    for i in words:
        answer += Node.getAnswer(root, i, 0)
    return answer
