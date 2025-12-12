//
// 2093G.cpp
// Created by Wasif on 12/12/25 at 11:43:09.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int tr[3000005][4]; 
int idx;

class BitTrie {
public:
    // Config: Adjust this based on problem constraints (e.g., 29 for 1e9)
    static const int MAX_BITS = 29; 

    static void init() {
        // Resetting only the root assumes we always start with fresh queries
        idx = 1;
        // Manual unroll / memset for root is faster than loop
        tr[1][0] = tr[1][1] = tr[1][2] = 0; 
    }

    static void insert(int x) {
        int cur = 1; // Root is 1
        for (int j = MAX_BITS; j >= 0; j--) {
            // Using 'bit' directly as index avoids branching logic
            int bit = (x >> j) & 1;
            
            if (!tr[cur][bit]) {
                int nxt = ++idx;
                tr[nxt][0] = tr[nxt][1] = tr[nxt][2] = 0; // Clear new node
                tr[cur][bit] = nxt;
            }
            
            cur = tr[cur][bit];
            tr[cur][2]++; // Index 2 is count
        }
    }

    static void remove(int x) {
        int cur = 1;
        for (int j = MAX_BITS; j >= 0; j--) {
            int bit = (x >> j) & 1;
            int nxt = tr[cur][bit];
            tr[nxt][2]--;
            cur = nxt;
            // No need to physically delete, count handles logical existence
        }
    }

    static int query(int x) {
        int cur = 1;
        int ans = 0;
        for (int j = MAX_BITS; j >= 0; j--) {
            int bit = (x >> j) & 1;
            int wanted = bit ^ 1;
            
            // Check child existence AND count > 0 in one line
            // Accessing tr[child][2] is fast because tr[child] is already loaded
            int nxt = tr[cur][wanted];
            if (nxt && tr[nxt][2] > 0) {
                ans |= (1 << j);
                cur = nxt;
            } else {
                cur = tr[cur][bit];
            }
        }
        return ans;
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        if(k == 0) {
            cout << 1 << '\n';
            continue;
        }
        auto f = [&] (int x) -> bool {
            BitTrie::init();
            BitTrie trie;
            for(int i = 0; i < x; i++) {
                trie.insert(a[i]);
            }
            for(int i = 0; i < x; i++) {
                int res = trie.query(a[i]);
                if(res >= k) return true;
            }
            for(int i = x; i < n; i++) {
                trie.remove(a[i - x]);
                int res = trie.query(a[i]);
                if(res >= k) {
                    return true;
                }
                trie.insert(a[i]);
            }
            return false;
        };
        if(!f(n)) {
            cout << -1 << '\n';
            continue;
        }
        int lo = 1, hi = n + 1;
        while(hi > lo + 1) {
            int mid = (hi + lo) / 2;
            if(f(mid)) hi = mid;
            else lo = mid;
        }
        cout << hi << '\n';
    }
}