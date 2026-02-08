//Bismillah
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define forn(i, a, n) for (int i = a; i < n; i++)
#define fornr(i, a, n) for (int i = n - 1; i >= a; i--)
#define print(a) cout << a << "\n";
#define printarr(a) forn(i, 0, a.size()) cout << a[i] << " "; cout << endl;
#define file_read(filepath) freopen(filepath, "r", stdin);
#define file_write(filepath) freopen(filepath, "w", stdout);
#define f first
#define s second
#define pb push_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sorted(a) is_sorted(all(a))
#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define vpii vector<pair<int,int>>
#define MOD1 1000000007
#define mii map<int,int>
#define sz(a) (int)a.size()
#define ld long double
#define add insert

struct Point {
    int x, y, i;
};

void solve(){
    int n, q;
    cin >> n >> q;
    vector<Point> pts;
    forn(i,0,n){
        int x, y;
        cin >> x >> y;
        int g = gcd(abs(x), abs(y));
        pts.pb({x / g, y / g, i});
    }
    auto where = [&](Point p){
        if(p.x == 0 and p.y > 0) return 1;
        if(p.x > 0 and p.y > 0) return 2;
        if(p.y == 0 and p.x > 0) return 3;
        if(p.x > 0 and p.y < 0) return 4;
        if(p.x == 0 and p.y < 0) return 5;
        if(p.x < 0 and p.y < 0) return 6;
        if(p.x < 0 and p.y == 0) return 7;
        return 8; 
    };
    auto cross = [&](Point a, Point b){
        return (a.x * b.y) - (b.x * a.y);
    };
    sort(all(pts), [&](auto a, auto b){
        int ra = where(a);
        int rb = where(b);
        if(ra != rb) return ra < rb;
        return cross(a, b) < 0; 
    });
    vi cnt; 
    vi id(n); 
    cnt.pb(1);
    id[pts[0].i] = 0;
    forn(i,1,n) {
        if (pts[i].x == pts[i-1].x and pts[i].y == pts[i-1].y) {
            cnt.back()++;
        } else {
            cnt.pb(1);
        }
        id[pts[i].i] = sz(cnt) - 1;
    }
    int m = sz(cnt);
    vi pre(m);
    pre[0] = cnt[0];
    forn(i,1,m) pre[i] = pre[i-1] + cnt[i];
    auto sum = [&](int i, int j) {
        return pre[j] - (i ? pre[i - 1] : 0);
    };
    while(q--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        int u = id[a];
        int v = id[b];
        int ans = 0;
        if (u <= v) {
            ans = sum(u, v);
        } else {
            ans = sum(u, m - 1) + sum(0, v);
        }
        print(ans)
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}