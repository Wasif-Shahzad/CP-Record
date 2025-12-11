//Bismillah
#include <bits/stdc++.h>
using namespace std;
//#define int long long int
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
#define sz(a) a.size()
#define ld long double
#define add insert

void solve(){
    int n, m;
    cin >> n >> m;
    vector<bitset<5000>> adj(5000);
    forn(i,0,m){
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(adj[i][j]){
                auto it = adj[i] & adj[j];
                int cnt = it.count();
                ans += cnt;
            }
        }
    }
    print(ans)
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    //cin >> t;
    while(t--){
    	solve();
	}
}