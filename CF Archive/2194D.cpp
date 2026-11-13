#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, m;
    cin >> n >> m;
    int tot = 0;
    vector<vector<int>> a(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
            tot += a[i][j];
        }
    }
    int sum = 0, i = -1, j = m, k = -5;
    bool vert = false;
    while (sum < tot / 2) {
        j--;
        for(int l = i + 1; l < n; l++) {
            sum += a[l][j];
            if (sum == tot / 2) {
                k = l;
                vert = true;
                break;
            }
        }
        if (sum == tot / 2) break;
        i++;
        for(int l = j - 1; l >= 0; l--) {
            sum += a[i][l];
            if (sum == tot / 2) {
                k = l;
                break;
            }
        }
    }
    cout << (tot + 1) / 2 * (tot / 2) << '\n';
    // cout << vert << " " << i << " " << j << " " << k << '\n';
    if (tot < 2) {
        for(int i = 0; i < n; i++) cout << "D";
        for(int i = 0; i < m; i++) cout << "R";
        cout << '\n';
        return;
    }
    if (vert) {
        int x = -1, y = -1;
        while (x < i) {
            cout << "D";
            x++;
        }
        while (y + 1 < j) {
            cout << "R";
            y++;
        }
        while (x < k) {
            cout << "D";
            x++;
        }
        y++;
        cout << "R";
        while (x + 1 < n) {
            cout << "D";
            x++;
        }
        while (y + 1 < m) {
            cout << "R";
            y++;
        }
        cout << '\n';
    } else {
        int x = -1, y = -1;
        while (x + 1 < i) {
            cout << "D";
            x++;
        }
        while (y + 1 < k) {
            cout << "R";
            y++;
        }
        x++;
        cout << "D";
        while (y +1 < j) {
            cout << "R";
            y++;
        }
        while (x + 1 < n) {
            cout << "D";
            x++;
        }
        while (y + 1 < m) {
            cout << "R";
            y++;
        }
        cout << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
