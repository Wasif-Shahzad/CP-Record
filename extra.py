t = int(input())
for _ in range(t):
    a, b, l = map(int, input().split())
    s = set()
    for i in range(19):
        for j in range(19):
            here = a**i * b**j
            if l % here == 0:
                s.add(here / l);
    print(len(s))
