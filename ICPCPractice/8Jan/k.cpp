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

const int maxn = 1e6;
vector<int> fact(maxn + 1), inv(maxn + 1);

int binpow(int a, int b, int m) {
    if(b == 0) return 1;
    int x = binpow(a, b / 2, m);
    if(b % 2 == 0)
        return (1LL * x * x) % m;
    else
        return (1LL * ((1LL * x * x) % m) * a) % m;
}

void pre(int m) {
    fact[0] = 1;
    for(int i = 1; i <= maxn; i++){
        fact[i] = (1LL * fact[i - 1] * i) % m;
    }
    inv[maxn] = binpow(fact[maxn], m - 2, m);
    for(int i = maxn - 1; i >= 0; i--){
        inv[i] = (1LL * inv[i + 1] * (i + 1)) % m;
    }
}

int ncr(int n, int r, int m) {
    if(r < 0 || r > n) return 0;
    return (1LL * fact[n] * inv[r] % m * inv[n - r]) % m;
}

void solve(){
    int m = 1000000009;
    int n;
    cin >> n;
    cout << ((binpow(2, (n + 1) % m, m) - (n % m) - 2) % m + m) % m << endl;
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
