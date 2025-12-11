//
// 1945F.cpp
// Created by Wasif on 12/01/25 at 10:44:27.
//

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
        int n;
        cin >> n;
        ordered_set oset;
        vector<int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            oset.insert({v[i], i});
        }
        vector<int> p(n);
        for(int i = 0; i < n; i++) {
            cin >> p[i];
            p[i]--;
        }
        int ans = *max_element(v.begin(), v.end()), k = 1;
        for(int i = 1; i < n; i++) {
            int prev = v[p[i - 1]];
            oset.erase({prev, p[i - 1]});
            int m = oset.size();
            int j = m - i - 1;
            if(j < 0) continue;
            auto [x, ii] = *oset.find_by_order(j);
            if(x * (i + 1) > ans) {
                ans = x * (i + 1);
                k = i + 1;
            }
        }
        cout << ans << " " << k << '\n';
    }    
}