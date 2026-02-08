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
    int cur = 0;
    vector<int> suff(n, 0), rs(n, 0);
    int prs = 0;
    for(int i = n - 1; i >= 0; i--) {
        if(s[i] == ')') cur++;
        else cur--, prs += 2;
        suff[i] = cur;
        rs[i] = prs;
    }
    vector<int> nxt(n, -1);
    int lst = -1;
    for(int i = n - 2; i >= 0; i--) {
        nxt[i] = lst;
        if(s[i] == '(') lst = i;
    }
    int ans = 0, bst = 0; cur = 0;
    bool good = false;
    for(int i = 0; i < n; i++) {
        if(s[i] == '(') cur++;
        else {
            int k = nxt[i];
            if(k == -1) continue;
            int rem = suff[k];
            if(rem >= cur) {
                int here = ans + 2 * cur + rs[k];
                bst = max(bst, here);
                good = true;
            } else if(rem + rs[k] / 2 >= cur) {
                int extra = cur - rem;
                int tmp = rs[k] - 2 * extra;
                if(tmp > 0) {
                    bst = max(bst, tmp + 2 * cur + ans);
                    good = true;
                }
            }
            cur--;
            ans += 2;
        }
    }
    if(good) cout << bst << '\n';
    else cout << -1 << '\n';
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