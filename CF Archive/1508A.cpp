//
// 1508A.cpp
// Created by wasifshahzad on 01/01/26 at 14:50:09.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define all(x) x.begin(), x.end()

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

int med(int x, int y, int z) {
    vector<int> a = {x, y, z};
    sort(all(a));
    return a[1];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        string a, b, c;
        cin >> a >> b >> c;
        int x = count(all(a), '0'), y = count(all(b), '0'), z = count(all(c), '0');
        int Y = med(x, y, z);
        if(Y >= n) {
            if(y > x) {
                swap(x, y);
                swap(a, b);
            }
            if(z > y) {
                swap(y, z);
                swap(b, c);
            }
            if(y > x) {
                swap(x, y);
                swap(a, b);
            }
            vector<int> l1(Y), l2(Y);
            int k = 0;
            for(int i = 0; i < 2 * n; i++) {
                if(a[i] == '0') {
                    l1[k++] = i;
                }
                if(k == Y) break;
            }
            k = 0;
            for(int i = 0; i < 2 * n; i++) {
                if(b[i] == '0') {
                    l2[k++] = i;
                }
                if(k == Y) break;
            }
            for(int i = 0; i < Y; i++) {
                int lst = -1;
                if(i > 0) lst = l1[i - 1];
                for(int j = lst + 1; j < l1[i]; j++) cout << a[j];
                lst = -1;
                if(i > 0) lst = l2[i - 1];
                for(int j = lst + 1; j < l2[i]; j++) cout << b[j];
                cout << 0;
            }
            for(int i = l1[Y - 1] + 1; i < 2 * n; i++) cout << a[i];
            for(int i = l2[Y - 1] + 1; i < 2 * n; i++) cout << b[i];
            cout << '\n';
        } else {
            Y = 2 * n - Y;
            x = 2 * n - x;
            y = 2 * n - y;
            z = 2 * n - z;
            if(y > x) {
                swap(x, y);
                swap(a, b);
            }
            if(z > y) {
                swap(y, z);
                swap(b, c);
            }
            if(y > x) {
                swap(x, y);
                swap(a, b);
            }
            vector<int> l1(Y), l2(Y);
            int k = 0;
            for(int i = 0; i < 2 * n; i++) {
                if(a[i] == '1') {
                    l1[k++] = i;
                }
                if(k == Y) break;
            }
            k = 0;
            for(int i = 0; i < 2 * n; i++) {
                if(b[i] == '1') {
                    l2[k++] = i;
                }
                if(k == Y) break;
            }
            for(int i = 0; i < Y; i++) {
                int lst = -1;
                if(i > 0) lst = l1[i - 1];
                for(int j = lst + 1; j < l1[i]; j++) cout << a[j];
                lst = -1;
                if(i > 0) lst = l2[i - 1];
                for(int j = lst + 1; j < l2[i]; j++) cout << b[j];
                cout << 1;
            }
            for(int i = l1[Y - 1] + 1; i < 2 * n; i++) cout << a[i];
            for(int i = l2[Y - 1] + 1; i < 2 * n; i++) cout << b[i];
            cout << '\n';
        }
    }
}