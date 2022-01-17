from itertools import combinations, permutations, product
import itertools

def is_marriage_stable(perm,women_pref, men_pref):
    w2m = {k:v for k,v in perm}
    m2w = {v:k for k,v in perm}
    for w,ms in women_pref.items():
        for m in ms:
            if m == w2m[w]: 
                break
            if men_pref[m].index(w) < men_pref[m].index(m2w[m]):
                return False
    return True


def main():
    l = [list(x) for x in permutations(["m1","m2","m3"])]
    x = itertools.product(l, repeat=3)
    w = [list(x) for x in permutations(["w1","w2","w3"])]
    mm = itertools.product(w, repeat=3)
    y = itertools.product(x, mm)
    z = list(y)
    count = 0
    for i in z:
        women_pref = { 
            "w1" : i[0][0],
            "w2" : i[0][1],
            "w3" : i[0][2],
        }
        men_pref =  {
            "m1" : i[1][0],
            "m2" : i[1][1],
            "m3" : i[1][2],
        }
        perm = [sorted(zip(i, men_pref.keys())) for i in permutations(women_pref.keys())]
        for j in perm:
            if not is_marriage_stable(j, women_pref, men_pref): 
                break
        else:
            print("All combination stable")
            print(i)
        count += 1
    print(count)



if __name__ == "__main__":
    main()
