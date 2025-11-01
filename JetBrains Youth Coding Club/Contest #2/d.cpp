//
// d.cpp
// Created by Wasif on 10/11/25 at 10:47:08.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    // consider it as a hypotenuse
    // represent it as N^2 + M^2
    int a = -1, b = -1;
    for(int i = 1; i * i < n; i++) {
        int rem = n - i * i;
        int s = sqrtl(rem);
        if(s * s == rem) {
            a = i, b = s;
            break;
        }
    }
    if(a != -1) {
        int A = 2 * a * b, B = abs(a * a - b * b);
        if(A > 0 && B > 0) {
            cout << A << " " << B << '\n';
            return 0;
        }
    }
    if(n % 2 == 0) {
        n /= 2;
        a = 1, b = n;
        int A = a * a + b * b, B = abs(a * a - b * b);
        if(A > 0 && B > 0) {
            cout << A << " " << B << '\n';
            return 0;
        } else {
            a = -1, b = -1;
            n *= 2;
        }
    } 
    for(int i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            int x = i, y = n / i;
            if(x > y) swap(x, y);
            if((x + y) % 2 == 0 && (x - y) % 2 == 0) {
                int M = (x + y) / 2, N = - (x - y) / 2;
                if(M > 0 && N > 0) {
                    a = M, b = N;
                    break;
                }
            }
        }
    }
    if(a != -1) {
        int A = 2 * a * b, C = a * a + b * b;
        cout << A << " " << C << '\n';
    } else {
        cout << -1 << '\n';
    }
}