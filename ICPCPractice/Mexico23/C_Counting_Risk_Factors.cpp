#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) (int)a.size()
#define V vector
#define ff first
#define ss second
#define rep(i, a, n) for (int i = a; i < n; i++)
#define rev(i, a, n) for(int i = a; i > n; i--)
#define out(a) cout << a << "\n"
#define outv(a) rep(i, 0, (int)a.size()) cout << a[i] << " "; cout << endl;
#define in(a) for(auto &i: a) cin >> i;
#define pb push_back
#define pii pair<int, int>
const int mod1 = 1e9+7, mod2 = 998244353;

void solve(){
    int n, k, l;
    cin >> n >> k >> l;
    string s, t;
    cin >> s >> t;
    vector<int> bad(26, 0);
    for(char x: t) bad[x - 'a']++;
    int cur = 0;
    map<int, int> cnt;
    int ans = 0;
    cnt[0] = 1;
    for(int i = 0; i < n; i++) {
        if(bad[s[i] - 'a']) cur++;
        ans += cnt[cur - k];
        cnt[cur]++;
    }
    out(ans);
}

signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}