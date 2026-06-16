//
// c.cpp
// Created by wasifshahzad on 03/28/26 at 20:37:50.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

/*
going from [l, r] to [l+1, r+1] means a[r+1] has to be in
either we remove a[l] and add a[r+1] i.e. a[l] = b[l] and a[r+1] = b[r+1]
or both stay inside and be same 
*/ 

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    vector<int> f1(n, 0), f2(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for(int i = 0; i < k; i++) {
        bool diff = false;
        for(int j = i + k; j < n; j += k) {
            if(a[j] != a[i]) {
                diff = true;
                break;
            }
        }
        if(diff) {
            for(int j = i; j < n; j += k) {
                if(a[j] != b[j] && b[j] != -1) {
                    cout << "NO\n";
                    return;
                }
                if(b[j] == -1) b[j] = a[j];
            }
        } else {
            int any = -1;
            for(int j = i; j < n; j += k) {
                if(b[j] != -1) {
                    any = b[j];
                    break;
                }
            }
            for(int j = i; j < n; j += k) {
                if(b[j] == -1) b[j] = any;
                else if(b[j] != b[i]) {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }
    for(int i = 0; i < k; i++) {
        f1[a[i] - 1]++;
        if(b[i] != -1) f2[b[i] - 1]++;
    }    
    for(int i = 0; i < n; i++) {
        if(f2[i] > f1[i]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}