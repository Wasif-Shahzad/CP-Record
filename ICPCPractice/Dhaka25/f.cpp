#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long int
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ld long double
#define nl cout << "\n";
#define getunique(v)                                  \
    {                                                 \
        sort(v.begin(), v.end());                     \
        v.erase(unique(v.begin(), v.end()), v.end()); \
    }
#define forn(a, b) for (int i = a; i < b; i++)
#define __builtin_popcountll __builtin_popcountll
#define __builtin_clzll __builtin_clzll
#define __builtin_ctzll __builtin_ctzll
#define yesno(b) cout << ((b) ? "YES" : "NO");
#define pii pair<int, int>
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define hhh cout << "here" << endl;
#define mod1 1000000007
#define mod2 998244353
const int inf = 1e17 + 1;
#define FL(i, a, n) for (int i = a; i < n; i++)
#define FR(i, a, n) for (int i = a; i >= n; i--)
void solve()
{
    int l, v, t, n;
    cin >> l >> v >> t >> n;
    int ans = 0;
    forn(0, n)
    {
        int tt, vv;
        cin >> tt >> vv;
        cout << 1 + ((t - tt) * abs(v - vv)) / l;
        if(i + 1 < n) cout << " ";
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
        nl;
    }
    return 0;
}