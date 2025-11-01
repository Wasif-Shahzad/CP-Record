t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    o = s.count('0') 
    one = (o > n - o)
    if one:
        print(n - o)
        for i in range(n):
            if s[i] == '1':
                print(i + 1, end=" ")
    else:
        print(o)
        for i in range(n):
            if s[i] == '0':
                print(i + 1, end=" ")
    print()