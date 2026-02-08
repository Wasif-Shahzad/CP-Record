#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

/*
*/

const int mod = 1e9+7;

struct Matrix{
    int n, m;
    vector<vector<int>> G;

    void init(int _n, int _m, vector<vector<int>> &_G) {
        n = _n, m = _m;
        G = _G;
    }

    Matrix operator*(const Matrix& other) const{
        assert(m == other.n);
        vector<vector<int>> res(n, vector<int>(other.m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < other.m; j++) {
                for(int k = 0; k < m; k++) {
                    res[i][j] = (res[i][j] + (G[i][k] * other.G[k][j]) % mod) % mod;
                }
            }
        }
        Matrix product;
        product.init(n, other.m, res);
        return product;
    }
};

Matrix power(Matrix a, int b) {
    int n = a.n, m = a.m;
    vector<vector<int>> I(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++) I[i][i] = 1;
    Matrix ans;
    ans.init(n, m, I);
    while(b > 0) {
        if(b & 1) ans = ans * a;
        a = a * a;
        b /= 2;
    }
    return ans;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, d, k, s;
    cin >> n >> d >> k >> s;
    vector<vector<int>> g(2 * n, vector<int>(2 * n, 0));
    for(int i = 0; i < n; i++) {
        g[i][n + i] = 1;
        for(int j = -d; j <= d; j++) {
            int K = ((i + j) % n + n) % n;
            g[i][K] = 1;
        }
    }
    for(int i = n; i < 2 * n; i++) g[i][i] = 1;
    Matrix G;
    G.init(2 * n, 2 * n, g);
    Matrix exp = power(G, k);
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans = (ans + exp.G[s - 1][n + i]) % mod;
    }
    cout << ans << '\n';
}