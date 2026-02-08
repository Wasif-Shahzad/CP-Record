//
// b.cpp
// Created by wasifshahzad on 01/08/26 at 07:10:51.
//

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;
typedef tree<
pair<int, int>,
null_type,
less<pair<int, int>>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for(int &i: a) cin >> i;
        set<int> st;
        vector<int> cnt(k + 1, 0);
        for(int i = 0; i <= k; i++) st.insert(i);
        for(int i = 0; i < k; i++) {
            if(a[i] <= k) {
                if(st.count(a[i])) st.erase(a[i]);
                cnt[a[i]]++;
            }
        }
        int ans = min(*st.begin(), k - 1);
        for(int i = k; i < n; i++) {
            if(a[i] <= k) {
                if(st.count(a[i])) st.erase(a[i]);
                cnt[a[i]]++;
            }
            if(a[i - k] <= k) {
                cnt[a[i - k]]--;
                if(cnt[a[i - k]] == 0) st.insert(a[i - k]);
            }
            ans = max(ans, min(*st.begin(), k - 1));
        }
        cout << ans << '\n';
    }
}