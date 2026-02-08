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

string OR(string& a, string& b) {
    string res;
    rep(i, 0, sz(a)) {
        if(a[i] == '1' || b[i] == '1') res += '1';
        else res += '0';
    }
    return res;
}

int popcnt(string s) {
    return count(all(s), '1');
}

void solve(){
    int n, m;
    cin >> n >> m;
    map<int, int> cnt;
    vector<string> a(n); in(a);
    rep(i, 0, n) {
        rep(j, i + 1, n) {
            cnt[popcnt(OR(a[i], a[j]))]++;
        }
    }
    auto [x, y] = *cnt.rbegin();
    cout << x << '\n';
    cout << y << '\n';
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