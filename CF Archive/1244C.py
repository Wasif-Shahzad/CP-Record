import sys

def gcd(a, b):
    if b == 0:
        return a, 1, 0
    d, x1, y1 = gcd(b, a % b)
    x = y1
    y = x1 - y1 * (a // b)
    return d, x, y

def find_any_solution(a, b, c):
    g, x0, y0 = gcd(abs(a), abs(b))
    if c % g != 0:
        return False, 0, 0, g
    x0 *= c // g
    y0 *= c // g
    if a < 0:
        x0 = -x0
    if b < 0:
        y0 = -y0
    return True, x0, y0, g

def _ceil(num, den):
    return (num // den) + 1 if num % den != 0 else num // den

def main():
    input = sys.stdin.readline
    n, p, w, d = map(int, input().split())
    a = d - w
    b = -w
    c = p - n * w
    # ya + zb = c
    here, y0, z0, g = find_any_solution(a, b, c)
    if not here:
        print(-1)
        return
    low = _ceil(g * (y0 + z0 - n), (a - b))
    hi = float('inf')
    low = max(low, _ceil(g * (n - y0), b))
    low = max(low, _ceil((z0 * g), a))
    hi = min(hi, (g * (z0 - n)) // a)
    hi = min(hi, (-y0 * g) // b)
    if hi < low:
        print(-1)
        return
    k = low
    y = y0 + k * (b // g)
    z = z0 - k * (a // g)
    x = n - y - z
    if x >= 0 and y >= 0 and z >= 0:
        print(x, y, z)
    else:
        print(-1)

if __name__ == "__main__":
    main()