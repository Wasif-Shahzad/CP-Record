//
// g.cpp
// Created by wasifshahzad on 04/30/26 at 21:00:21.
//

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

typedef tree<
pair<int, int>,
null_type,
less<pair<int, int>>,
rb_tree_tag,
tree_order_statistics_node_update>
oset;

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

void solve() {
    // for a subsegment we need to start from corners
    // so from start from first 2 indices
    // for second index, we want all to go
    // jis element ko rakhengein uske left right greedy marna hoga
    // the corner element stays forever
    // fk, we have to remove the middle and do an operation on last 2
    // c[i] - c[i + 1] + c[i + 2], c[i + 3], c[i + 4]
    // c[i] - c[i + 1] + c[i + 2] - c[i + 3] + c[i + 4]
    // we can't go further if alternating sum <= 0
    // we need to count where alternating sum > 0
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> p1(n + 1, 0), p2(n + 1, 0);
    oset s1, s2;
    int ans = n;
    for(int i = 1; i <= n; i++) {
        p1[i] = p1[i - 1];
        p2[i] = p2[i - 1];
        if(i & 1) {
            p1[i] += a[i];
            p2[i] -= a[i];
        } else {
            p1[i] -= a[i];
            p2[i] += a[i];
        }
        if(i >= 3 && (i & 1)) {
            s1.insert({p1[i - 3], i - 3});
        }
        if(i >= 4 && (i & 1^1)) {
            s2.insert({p2[i - 3], i - 3});
        }
        if(i & 1) {
            ans += s1.order_of_key({p1[i], 0});
        } else {
            ans += s2.order_of_key({p2[i], 0});
        }
    }
    cout << ans << '\n';
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