//
// 1981B.cpp
// Created by Wasif on 09/10/25 at 15:16:23.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int MSBPosition(int N)
{
    int msb_p = -1;
    while (N) {
        N = N >> 1;
        msb_p++;
    }
    return msb_p;
}

// Returns the Bitwise OR of all
// integers between L and R
int findBitwiseOR(int L, int R)
{
  if(L==R)
    return L;
  
    int res = 0;

    // Find the MSB position in L
    int msb_p1 = MSBPosition(L);

    // Find the MSB position in R
    int msb_p2 = MSBPosition(R);

    while (msb_p1 == msb_p2) {
        int res_val = (1 << msb_p1);

        // Add this value until msb_p1 and
        // msb_p2 are same;
        res += res_val;

        L -= res_val;
        R -= res_val;

        // Calculate msb_p1 and msb_p2
        msb_p1 = MSBPosition(L);
        msb_p2 = MSBPosition(R);
    }
    // Find the max of msb_p1 and msb_p2
    msb_p1 = max(msb_p1, msb_p2);

    // Set all the bits from msb_p1 upto
    // 0th bit in the result
    for (int i = msb_p1; i >= 0; i--) {
        int res_val = (1 << i);
        res += res_val;
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        int n, m;
        cin >> n >> m;
        cout << findBitwiseOR(max(0ll, n - m), n + m) << '\n';
    }
}