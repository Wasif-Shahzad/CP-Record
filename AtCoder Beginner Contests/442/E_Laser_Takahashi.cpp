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

struct Point {
    int x, y, id;
    int region() {
        if(x == 0 && y > 0) return 1;
        if(x > 0 && y > 0) return 2;
        if(x > 0 && y == 0) return 3;
        if(x > 0 && y < 0) return 4;
        if(x == 0 && y < 0) return 5;
        if(x < 0 && y < 0) return 6;
        if(x < 0 && y == 0) return 7;
        return 8;
    }
};

int crossprod(Point a, Point b) {
    return a.x * b.y - a.y * b.x;
}

bool cmp(Point& a, Point& b) {
    if(a.region() != b.region()) {
        return a.region() < b.region();
    }
    return crossprod(a, b) < 0;
}

void solve(){
    int n, q;
    cin >> n >> q;
    V<Point> a(n);
    rep(i, 0, n) {
        cin >> a[i].x >> a[i].y;
        a[i].id = i;
    }
    sort(all(a), cmp);
    V<int> pt(n);
    V<int> pref = {1};
    int j = 0;
    pt[a[0].id] = 0;
    rep(i, 1, n) {
        if(a[i].region() == a[i - 1].region() && crossprod(a[i - 1], a[i]) == 0) {
            pref.back()++;
            pt[a[i].id] = j;
        } else {
            pref.pb(pref.back() + 1);
            pt[a[i].id] = ++j;
        }
    }
    while(q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        if(pt[r] >= pt[l]) {
            int sub = (pt[l] > 0 ? pref[pt[l] - 1] : 0);
            cout << pref[pt[r]] - sub << '\n';
        } else {
            int sub = (pt[l] > 0 ? pref[pt[l] - 1] : 0);
            int ans = pref.back() - sub;
            ans += pref[pt[r]];
            cout << ans << '\n';
        }
    }
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