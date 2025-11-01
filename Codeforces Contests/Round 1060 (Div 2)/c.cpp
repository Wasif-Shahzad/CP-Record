//
// c.cpp
// Created by Wasif on 10/19/25 at 20:27:38.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int MAXN = 2e5+5;
int spf[MAXN];
vector<int> freq(MAXN, 0), potfreq(MAXN, 0), pmn(MAXN, 1e10);

vector<int> pf(int x) {
    vector<int> res;
    while(x != 1) {
        int tmp = spf[x];
        while(x % tmp == 0) x /= tmp;
        res.push_back(tmp);
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    iota(spf, spf + MAXN, 0);
    for(int i = 2; i < MAXN; i++) {
        if(spf[i] == i) {
            for(int j = i * i; j < MAXN; j += i) {
                if(spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> our, pour;
        vector<int> a(n), b(n);
        pair<int, int> mn = {1e10, 1e10};
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for(int i = 0; i < n; i++) {
            cin >> b[i];
        }
        for(int i = 0; i < n; i++) {
            auto fact = pf(a[i]);
            for(int p: fact) {
                our.push_back(p);
                freq[p]++;
            }
            fact = pf(a[i] + 1);
            for(int p: fact) {
                potfreq[p]++;
                pour.push_back(p);
                pmn[p] = min(pmn[p], b[i]);
                if(p == 2) {
                    if(b[i] < mn.first) {
                        swap(mn.first, mn.second);
                        mn.first = b[i];
                    } else {
                        mn.second = min(mn.second, b[i]);
                    }
                }
            }
        }
        sort(our.begin(), our.end());
        our.erase(unique(our.begin(), our.end()), our.end());
        sort(pour.begin(), pour.end());
        pour.erase(unique(pour.begin(), pour.end()), pour.end());
        bool good = false;
        for(int i: our) {
            if(freq[i] >= 2) {
                good = true;
                break;
            }
        }
        if(good) {
            cout << 0 << '\n';
        }
        else {
            vector<pair<int, int>> tmp(n);
            for(int i = 0; i < n; i++) {
                tmp[i] = {a[i], b[i]};
            }
            sort(tmp.begin(), tmp.end(), [&] (auto x, auto y) {
                return x.second < y.second;
            });
            int ans = 1e15;
            for(int p: our) {
                if(potfreq[p]) {
                    ans = min(ans, pmn[p]);
                }
            }
            for(int p: our) {
                if(tmp[0].first % p == 0) continue;
                int need = (p - (tmp[0].first % p)) % p;
                ans = min(ans, need * tmp[0].second);
            }
            ans = min(ans, {mn.first + mn.second});
            cout << ans << '\n';
        }
        for(int i: our) {
            freq[i] = 0;
        }
        for(int i: pour) {
            potfreq[i] = 0;
            pmn[i] = 1e10;
        }
    }
}