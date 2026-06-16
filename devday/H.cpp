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
#define f(i, s, e)  for(int i = s;i<e;i++)
#define rev(i, a, n) for(int i = a; i > n; i--)
#define out(a) cout << a << "\n"
#define outv(a) for(auto &asdlfkjas: a) { cout << asdlfkjas << " "; } cout << '\n';
#define in(a) for(auto &i: a) cin >> i;
#define pb push_back
#define pii pair<int, int>
const int mod1 = 1e9+7, mod2 = 998244353;
bool check(vector<vector<int>> a) {
    vector<bool> mark(10, false);
    f(i, 0, 3){
        f(j, 0, 3){
            if(mark[a[i][j]])  return false;
            mark[a[i][j]] = true;
            if(a[i][j]<=0 or a[i][j]>9) return false;
        }
    }
    int s = a[0][0] + a[0][1] + a[0][2];
    for(int i = 0; i < 3; i++) {
        if(a[i][0] + a[i][1] + a[i][2] != s) return false;
        if(a[0][i] + a[1][i] + a[2][i] != s) return false;
    }
    if(a[0][0] + a[1][1] + a[2][2] != s) return false;
    if(a[0][2] + a[1][1] + a[2][0] != s) return false;
    return true;
}
void solve(){
    vector<vector<int>> grid(3, vector<int> (3));
    for(auto &value : grid){
        for(auto &x : value)
            cin>>x;
    }
    int req = 15, globalans = INT_MAX;
    vector<vector<int>> ans(3, vector<int> (3, 0));
    f(i, 1, 10){
        ans[0][0] =i;
        int rem  = req - i;
        f(j, 1, rem){
            ans[0][1] = j;
            ans[0][2] = rem - j;
            f(k, 1, rem){
                ans[1][0] = k;
                ans[2][0] = rem - k;
                
                ans[1][1] = req - ans[0][2] - ans[2][0];
                ans[1][2] = req - ans[1][0] - ans[1][1];
                ans[2][1] = req - ans[0][1] - ans[1][1];
                ans[2][2] = req - ans[2][0] - ans[2][1];
                // if(i == 4 and j == 9 and k == 3){
                //     f(x, 0, 3){
                //         f(y, 0, 3){
                //             cout<<ans[x][y]<<" ";
                //         }
                //         cout<<endl;
                //     }
                // }
                if(not check(ans))  continue;
                int asdf = 0;
                f(x, 0, 3){
                    f(y, 0, 3){
                        asdf += abs(ans[x][y] - grid[x][y]);
                    }
                }
                globalans= min(globalans, asdf);
            }
        }
        
    }
    cout<<globalans<<endl;
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