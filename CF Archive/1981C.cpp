//
// 1981C.cpp
// Created by wasifshahzad on 12/31/25 at 16:09:11.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

// 16 8 4 9 18

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        if(count(a.begin(), a.end(), -1) == n) {
            for(int i = 0; i < n; i++) {
                cout << ((i & 1) ? 2 : 1) << " ";
            }
            cout << '\n';
            continue;
        }
        int j = 0;
        while(a[j] == -1) j++;
        for(int i = j - 1; i >= 0; i--) {
            if(a[i + 1] == 1) a[i] = 2;
            else a[i] = a[i + 1] / 2;
        }
        int l = j;
        j = n - 1;
        while(a[j] == -1) j--;
        for(int i = j + 1; i < n; i++) {
            if(a[i - 1] == 1) a[i] = 2;
            else a[i] = a[i - 1] / 2;
        }
        int r = j;
        if(l == r) {
            for(int i = 0; i < n; i++) cout << a[i] << " ";
            cout << '\n';
            continue;
        }
        bool bad = false;
        for(int i = 1; i < n; i++) {
            if(a[i] != -1 && a[i - 1] != -1 && !(a[i] == a[i - 1] / 2 || a[i - 1] == a[i] / 2)) {
                bad = true;
                break;
            }
        }
        if(bad) {
            cout << -1 << '\n';
            continue;
        }
        auto div = [&] (int x, int y) -> bool {
            if(x < y) swap(x, y);
            if(x == y) return true;
            while(x > 0) {
                x /= 2;
                if(x == y) return true;
            }
            return false;
        };
        auto check = [&] (int x, int y) -> pair<int, int> {
            if(div(x, y)) return {-1, -1};
            for(int i = 0; i < 30; i++) {
                if(x / (1 << i) == 0) continue;
                for(int j = 0; j < 30; j++) {
                    if(y / (1 << j) == 0) continue;
                    if(x / (1 << i) == y / (1 << j)) return {i, j};
                }
            }
            return {-1, -1};
        };
        auto solve = [&] (int x, int y, int m) -> deque<int> {
            pair<int, int> h = check(x, y);
            if(h.first > 0 && h.second > 0) {
                if(h.first + h.second > m) return {-1};
                deque<int> d(m);
                int i = 0, j = m - 1;
                for(int k = 0; k < h.first; k++) {
                    d[i] = x;
                    x /= 2;
                    i++;
                }
                for(int k = 0; k < h.second; k++) {
                    d[j] = y;
                    y /= 2;
                    j--;
                }
                int rem = j - i;
                if(rem & 1) return {-1};
                while(i <= j) {
                    d[i] = d[i - 1] / 2;
                    if(d[i] == 0) d[i] = 2;
                    d[j] = (d[j + 1]) / 2;
                    if(d[j] == 0) d[j] = 2;
                    i++, j--;
                }
                return d;
            }
            deque<int> d;
            deque<int> tmp;
            if(div(x, y)) {
                if(x > y) {
                    while(x >= y) {
                        d.push_back(x);
                        x /= 2;
                    }
                    while((int)d.size() + 2 <= m) {
                        d.push_back(2 * y);
                        d.push_back(y);
                    }
                    if((int)d.size() < m) {
                        return {-1};
                    }
                } else {
                    while(y >= x) {
                        d.push_front(y);
                        y /= 2;
                    }
                    while((int)d.size() + 2 <= m) {
                        d.push_front(2 * x);
                        d.push_front(x);
                    }
                    if((int)d.size() < m) return {-1};
                }
            } else {
                while(x > 0) {
                    d.push_back(x);
                    x /= 2;
                }
                while(y > 0) {
                    if(y != 1) tmp.push_front(y);
                    y /= 2;
                }
            }
            int sz = (int)d.size() + (int)tmp.size();
            if(sz > m) return {-1};
            if((m - sz) & 1) return {-1};
            while(sz < m) {
                if(d.back() == 1) {
                    d.push_back(2);
                    d.push_back(1);
                } else {
                    d.push_back(1);
                    d.push_back(2);
                }
                sz += 2;
            }
            for(int i: tmp) d.push_back(i);
            return d;
        };
        int x = a[l], m = 1;
        bool need = false;
        for(int i = l + 1; i <= r; i++) {
            m++;
            if(a[i] == -1) {
                need = true;
                continue;
            }
            if(!need) {
                x = a[i], m = 1;
                continue;
            }
            int y = a[i];
            auto res = solve(x, y, m);
            if(res[0] == -1) {
                bad = true;
                break;
            }
            for(int j = i - m + 1, k = 0; j <= i; j++, k++) {
                a[j] = res[k];
            }
            x = a[i], m = 1;
            need = false;
        }
        if(bad) cout << -1 << '\n';
        else {
            for(int i = 0; i < n; i++) cout << a[i] << " ";
            cout << '\n';
        }
    }
}