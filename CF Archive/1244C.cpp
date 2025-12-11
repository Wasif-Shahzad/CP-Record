//
// 1244C.cpp
// Created by Wasif on 12/10/25 at 15:15:55.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool find_any_solution(long long a, long long b, long long c, 
                       long long &x0, long long &y0, long long &g) {
    
    // 1. Calculate GCD using normal long long
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) return false;

    // 2. Use __int128 for the scaling step to avoid overflow
    __int128 temp_x0 = x0;
    __int128 temp_y0 = y0;
    
    temp_x0 *= c / g;
    temp_y0 *= c / g;

    // We can't return these huge values directly in long long reference parameters.
    // However, for the shift logic later, we usually need these values.
    // In this specific problem, we can shift them *now* to bring them back 
    // into valid long long range immediately.
    
    // Shift logic: x = x0 + k * (b/g)
    // We want x to be relatively small (e.g., close to 0) to fit in long long.
    long long bg = b / g;
    long long ag = a / g;
    
    // Calculate k to bring temp_x0 near 0
    // k = -(temp_x0 / bg)
    __int128 k = -(temp_x0 / bg);
    
    temp_x0 += k * bg;
    temp_y0 -= k * ag;
    
    // Now they fit in long long!
    x0 = (long long)temp_x0;
    y0 = (long long)temp_y0;
    
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    
    return true;
}

int _ceil(int num, int den) {
    int ans = num / den;
    if(num % den != 0 && (num ^ den) < 0) ans++;
    return ans;
}

int _floor(int num, int den) {
    int ans = num / den;
    if(num % den != 0 && ((num ^ den) >= 0)) ans--;
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, p, w, d;
    cin >> n >> p >> w >> d;
    int a = d - w, b = -w, c = p - n * w;
    // ya + zb = c
    int y0, z0, g;
    bool here = find_any_solution(a, b, c, y0, z0, g);
    if(!here) {
        cout << -1 << '\n';
        return 0;
    }
    int low = _ceil(g * (y0 + z0 - n), (a - b)), hi = LONG_LONG_MAX;
    low = max(low, _ceil(g * (n - y0), b));
    low = max(low, (z0 * g) / a);
    hi = min(hi, _ceil(g * (z0 - n), a));
    hi = min(hi, (-y0 * g) / b);
    if(hi < low) {
        cout << -1 << '\n';
        return 0;
    }
    int k = low;
    int y = y0 + k * (b / g);
    int z = z0 - k * (a / g);
    int x = n - y - z;
    if(x >= 0 && y >= 0 && z >= 0) {
        cout << x << " " << y << " " << z << '\n';
    } else {
        cout << -1 << '\n';
    }
}