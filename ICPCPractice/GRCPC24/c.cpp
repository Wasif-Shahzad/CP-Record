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
#define ld long double
ld pi = acos(-1);
ld eps = 1e-6;

void solve(){
    int x1, y1, x2, y2, x, y, r;
    cin >> x1 >> y1 >> x2 >> y2 >> x >> y >> r;
    int len = y2 - y1;
    ld tot = (x2 - x1) * (y2 - y1) - pi * r * r;
    ld target = tot / 2;
    auto f = [&] (ld _x) -> ld {
        ld here = (_x - x1) * len;
        if(abs(_x - x) > r) {
            if(_x > x) {
                here -= pi * r * r;
            }
            return here;
        }
        ld dist = abs(_x - x);
        if(dist < eps) return here - (pi * r * r) / 2.0;
        ld half_chord = sqrtl(r * r - dist * dist);
        ld tot_area = dist * half_chord;
        ld theta = acos(dist / r);
        ld area_sector = r * r * theta;
        ld slice_area = area_sector - tot_area;
        if (_x < x) here -= slice_area;
        else here -= pi * r * r - slice_area;
        return here;
    };
    auto g = [&] (ld _x) -> bool {
        return f(_x) < target;
    };
    ld lo = x1, hi = x2;
    for(int i = 0; i < 200; i++) {
        ld mid = (lo + hi) / 2;
        if(g(mid)) lo = mid;
        else hi = mid;
    }
    cout << fixed << setprecision(4) << lo << '\n';
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