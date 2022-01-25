def r(s, l, c, d):
    if c == k:
        d = True
    if l == n:
        if d:
            print(s)
    else:
        r(s+"0", l+1, 0, d)
        r(s+"1", l+1, c+1, d)


n, k = (int(x) for x in input().split())
r("", 0, 0, False)
