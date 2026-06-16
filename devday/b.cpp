//
// b.cpp
// Created by wasifshahzad on 04/30/26 at 13:18:50.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

void solve() {
    int n,m;
    cin>>n>>m;
    vector<vector<char>> arr(n,vector<char>(m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>arr[i][j];
    vector<vector<int>> mn(n,vector<int>(m,LLONG_MAX));
    for(int i=0;i<n;i++)
    {
        int cur = 0;
        for(int j=0;j<m;j++)
        {
            mn[i][j] = min(mn[i][j],cur);
            if(arr[i][j]=='^')
                cur++;
            else
                cur = 0;
        }
    }
    for(int i=0;i<n;i++)
    {
        int cur = 0;
        for(int j=m-1;j>=0;j--)
        {
            mn[i][j] = min(mn[i][j],cur);
            if(arr[i][j]=='^')
                cur++;
            else
                cur = 0;
        }
    }
    for(int j=0;j<m;j++)
    {
        int cur = 0;
        for(int i=0;i<n;i++)
        {
            mn[i][j] = min(mn[i][j],cur);
            if(arr[i][j]=='^')
                cur++;
            else
                cur = 0;
        }
    }
    for(int j=0;j<m;j++)
    {
        int cur = 0;
        for(int i=n-1;i>=0;i--)
        {
            mn[i][j] = min(mn[i][j],cur);
            if(arr[i][j]=='^')
                cur++;
            else
                cur = 0;
        }
    }
    int sum = 0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(mn[i][j]>=2 and arr[i][j]=='^')
                sum++;
    cout<<sum<<"\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}