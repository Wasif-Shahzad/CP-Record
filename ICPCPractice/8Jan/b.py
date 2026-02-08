import sys

inp = []
for line in sys.stdin:
    s = line.strip()
    if s:
        inp.append(s)

n = len(inp)
i = 0
while True:
    if inp[i][-1] == '$':
        if i + 1 < len(inp) and inp[i + 1][0:2] != "$$":
            nxt = inp.pop(i + 1)
            inp[i] = inp[i][:-1]
            inp[i] += nxt
    else:
        i += 1
    if i == len(inp):
        break
i = 0
while True:
    if inp[i][0:2] == "$$":
        inp.pop(i)
    else:
        i += 1
    if i == len(inp):
        break

for v in inp:
    print(v)