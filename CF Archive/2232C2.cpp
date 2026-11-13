#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    /*
     * we want the ith introvert to be in the range [1, s * (i - 1) + 1]
     * if no we find the next introvert and do the +s from there all over again
     */
    int n, x, s;
    cin >> n >> x >> s;
    string a;
    cin >> a;
    int i = 0;
    while (i < n && a[i] == 'E') i++;
    if (i == n) {
        cout << 0 << '\n';
        return;
    }
    a[i] = 'I';
    i++;
    int avail = s - 1, ambi = 0, ans = 1;
    x--;
    while (i < n) {
        if (a[i] == 'I') {
            // cout << x << '\n';
            if (x > 0) {
                avail += s - 1;
                x--;
                ans++;
            }
        } else if (a[i] == 'E') {
            if (avail > 0) {
                if (ambi == avail) {
                    if (x > 0) {
                        x--;
                        avail += s - 2;
                        ambi--;
                        ans += 2;
                    }
                } else {
                    avail--;
                    ans++;
                }
            } else if(ambi > 0 && x > 0) {
                ambi--;
                avail += s - 2;
                ans += 2;
                x--;
            }
        } else {
            if (avail == 0) {
                if (x > 0) {
                    x--;
                    avail += s - 1;
                    ans++;
                }
            } else {
                if (ambi == avail) {
                    if (x > 0) {
                        x--;
                        avail += s - 1;
                        ans++;
                    }
                } else {
                    ambi++;
                }
            }
        }
        // cout << i << " " << ambi << '\n';
        i++;
    }
    // cout << ans << " " << ambi << " " << avail << '\n';
    ans += min(ambi, avail);
    cout << ans << '\n';
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
