//
// h.cpp
// Created by Wasif on 10/23/25 at 19:34:08.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

vector<vector<int>> d;
vector<int> fix;
int n, k;

bool solve(int i, int s) {
  if(s == k) {
    return true;
  }
  if(i > n) {
    return false;
  }
  if(s > k) {
    return false;
  }
  int add = 0;
  fix[i] = 1;
  for(int j: d[i]) {
    add += fix[j];
  }
  if(solve(i + 1, s + add)) {
    return true;
  }
  fix[i] = 0;
  if(solve(i + 1, s)) {
    return true;
  }
  return false;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> k;
  int total = 0;
  fix.resize(n + 1, 0);
  d.resize(n + 1);
  for(int i = 1; i <= n; i++) {
    for(int j = 2 * i; j <= n; j += i) {
      d[j].push_back(i);
      total++;
    }
  }
  if(k <= total && solve(1, 0)) {
    cout << "Yes\n";
    vector<int> res;
    for(int i = 1; i <= n; i++) {
      if(fix[i]) res.push_back(i);
    }
    cout << res.size() << '\n';
    for(int i: res) cout << i << " ";
    cout << '\n';
  } else {
    cout << "No\n";
  }
}