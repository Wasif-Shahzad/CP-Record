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
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(is_sorted(all(s))) {
        out("Bob");
        return;
    }
    int z = count(all(s), '0'), o = n - z;
    vector<int> ind;
    int j = -1;
    int cur = 0;
    rep(i, 0, n) {
        if(s[i] == '1') {
            cur++;
            ind.push_back(i);
        }
        else z--;
        if(cur == z) {
            j = i;
            break;
        }
    }
    for(int i = j; i < n; i++) {
        if(s[i] == '0') ind.push_back(i);
    }
    cout << "Alice\n";
    cout << ind.size() << '\n';
    for(int i: ind) cout << i + 1 << ' ';
    cout << '\n';
}

signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}