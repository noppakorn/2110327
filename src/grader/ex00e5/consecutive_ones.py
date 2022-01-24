import sys
def recur(l):
    if l == len(v):
        count = 0
        for x in v:
            if x: 
                count += 1
                if count >= k:
                    for i in v:
                        print(1 if i else 0, end="")
                    print()
                    return
            else:
                count = 0
    else:
        v[l] = False
        recur(l+1)
        v[l] = True
        recur(l+1)
n, k = map(int, sys.stdin.readline().split())
v = [False]*n
recur(0)
