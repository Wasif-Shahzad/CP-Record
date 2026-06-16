#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

bool solve(int r, int c, int n, int m, int a, int b, vector<int>& row_counts, vector<int>& col_counts, vector<vector<int>>& matrix) {
    // Base case: we have successfully filled the entire matrix
    if (r == n) {
        // Verify that all rows have exactly 'a' ones and columns have exactly 'b' ones
        for (int i = 0; i < n; ++i) {
            if (row_counts[i] != a) return false;
        }
        for (int j = 0; j < m; ++j) {
            if (col_counts[j] != b) return false;
        }
        return true;
    }

    // Determine the coordinates for the next cell
    int next_r = r;
    int next_c = c + 1;
    if (next_c == m) {
        next_r = r + 1;
        next_c = 0;
    }

    // Option 1: Place a 0
    matrix[r][c] = 0;
    if (solve(next_r, next_c, n, m, a, b, row_counts, col_counts, matrix)) {
        return true;
    }

    // Option 2: Place a 1
    // Pruning: Only place a 1 if we haven't exceeded the target counts for this row or column
    if (row_counts[r] < a && col_counts[c] < b) {
        matrix[r][c] = 1;
        row_counts[r]++;
        col_counts[c]++;
        
        if (solve(next_r, next_c, n, m, a, b, row_counts, col_counts, matrix)) {
            return true;
        }
        
        // Backtrack
        row_counts[r]--;
        col_counts[c]--;
    }

    return false;
}

bool hasValidMatrix(int n, int m, int a, int b) {
    // Mathematical impossibility check: total 1s by rows must equal total 1s by columns
    if (n * a != m * b) {
        return false;
    }

    vector<vector<int>> matrix(n, vector<int>(m, 0));
    vector<int> row_counts(n, 0);
    vector<int> col_counts(m, 0);

    return solve(0, 0, n, m, a, b, row_counts, col_counts, matrix);
}

void solve() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    string x;
    vector<vector<int>> our(n, vector<int>(m));
    cin >> x;
    bool res = hasValidMatrix(n, m, a, b);
    if(x == "YES" && res == 0) {
        cout << "Solution doesn't Exist\n";
        return;
    }
    if(x == "NO" && res == 1) {
        cout << "Solution exists\n";
        return;
    }
    if(x == "NO") {
        cout << "OK\n";
        return;
    }
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < m; j++) {
            our[i][j] = s[j] - '0';
        }
    }
    bool good = true;
    for(int i = 0; i < n; i++) {
        int cur = 0;
        for(int j = 0; j < m; j++) cur += our[i][j];
        if(cur != a) {
            cout << "Row: " << i << " doesn't have a ones\n";
            return;
        }
    }
    for(int j = 0; j < m ;j++) {
        int cur = 0;
        for(int i = 0; i < n; i++) cur += our[i][j];
        if(cur != b) {
            cout << "Col: " << j << " doesn't have b ones\n";
            return;
        }
    }
    cout << "OK\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}
