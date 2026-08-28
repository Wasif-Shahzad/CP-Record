#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    /*
     * we need sum(b) = sum(c)
     * for a subtree S, if sum(S_b) = sum(S_c) then we check the equals and not equals.
     * our cost can be countDiff(S) * a[S]
     * if sum(S_b) > sum(S_c) we want to send some 1s outside
     * how to decide which to send?
     * 2 * (count of those where we need 1 but there is 0) * a[S]?
     *
     * another approach just got:
     * for each incorrect node u, we take the parent with the lost a[p] such that the parent has an opposite unmatching pair. so if at node u we have 1, need 0. find a parent p which has a node which has 0 and needs 1. this can be done with binary lifting and then get the min of all parents from there upwards, multiply by 2, add to answer and simulate the results. i.e. in all our parents subtract a (1, 0), in all their parents subtract a (0, 1)
     * this is greedy tho.... not guaranteed to work.
     * from here we can also say that for a subtree the cost is min(cnt of 01, cnt of 10) * 2 * a[v]
     * how the heck to formulate a dp out of it :sob:
     * abs(cnt of 01 - cnt of 10) propagates upwards as well
     * if we go top down then we can get the min in the current branch and assign all possible matches with that and add. i guess, this works.
     * there can be some tricky situations where we go down the branch and we fail cuz of mismatches... so this shouldn't work ideally FFs
     */
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n), c10(n, 0), c01(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
        c10[i] += (b[i] - c[i] == 1);
        c01[i] += (b[i] - c[i] == -1);
        // cout << c01[i] << " ";
    }
    // cout << '\n';
    vector<vector<int>> g(n);
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if(accumulate(b.begin(), b.end(), 0ll) != accumulate(c.begin(), c.end(), 0ll)) {
        cout << -1 << '\n';
        return 0;
    }
    auto push_min = [&] (int v, int p, auto&& self) -> void {
        for(int c: g[v]) {
            if(c == p) continue;
            a[c] = min(a[c], a[v]);
            self(c, v, self);
            c10[v] += c10[c];
            c01[v] += c01[c];
        }
    };
    push_min(0, -1, push_min);
    int ans = a[0] * 2 * c01[0];
    // cout << c01[0] << " " << c10[0] << '\n';
    auto dfs = [&] (int v, int p, auto&& self) -> void {
        if(p != -1 && a[p] != a[v]) {
            ans -= a[p] * 2 * min(c01[v], c10[v]);
            ans += a[v] * 2 * min(c01[v], c10[v]);
        }
        for(int c: g[v]) {
            if(c == p) continue;
            self(c, v, self);
        }
    };
    dfs(0, -1, dfs);
    cout << ans << '\n';
}
