def solution(id_pw, db):
    answer = ''
    c = {}
    for i, p in db:
        c[i] = p
    if id_pw[0] not in c: return "fail"
    elif c[id_pw[0]] != id_pw[1] : return "wrong pw"
    return "login"