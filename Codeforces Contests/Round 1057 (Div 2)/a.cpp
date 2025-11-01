//
// a.cpp
// Created by Wasif on 10/10/25 at 19:25:08.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int find_lis(const vector<int> &a) {

	int lis = 0;

	vector<int> dp(a.size(), 1);

	for (int i = 0; i < a.size(); i++) {

		for (int j = 0; j < i; j++) {

			if (a[j] < a[i]) { dp[i] = max(dp[i], dp[j] + 1); }

		}

		lis = max(lis, dp[i]);

	}

	return lis;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        cout << a.size() << '\n';
    }
}