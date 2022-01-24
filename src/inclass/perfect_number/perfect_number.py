def perfect_number(a,b):
    for i in range(a,b):
        if sum([j for j in range(1,i) if i % j == 0]) == i: return i
    return -1

def main():
    a,b = [int(i) for i in input().split()]
    print(perfect_number(a,b))

if __name__ == "__main__":
    main()
