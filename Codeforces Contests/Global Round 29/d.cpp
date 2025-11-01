//
// d.cpp
// Created by Wasif on 09/20/25 at 21:04:03.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        set<int> blocked, all;
        priority_queue<array<int, 2>> pq;
        map<int, int> freq;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            freq[a[i]]++;
            all.insert(a[i]);
        }
        for(int i: all) if(all.count(i + 1)) blocked.insert(i + 1);
        for(int i: all) {
            if(!blocked.count(i)) {
                pq.push({freq[i], i});
            }
        }
        int alice = 0, bob = 0;
        bool turn = true;
        while(pq.size()) {
            auto [f, i] = pq.top();
            pq.pop();
            auto it = all.lower_bound(i);
            if(it == all.begin()) {
                if(turn) {
                    alice += f * ((i + 1) / 2);
                    bob += f * (i / 2);
                } else {
                    alice += f * (i / 2);
                    bob += f * ((i + 1) / 2);
                }
                turn = !turn;
                if(blocked.count(i + 1)) {
                    pq.push({freq[i + 1], i + 1});
                    blocked.erase(i + 1);
                }
                all.erase(i);
            } else {
                it--;
                int moves = i - *it - 1;
                if(turn) {
                    alice += f * ((moves + 1) / 2);
                    bob += f * (moves / 2);
                } else {
                    alice += f * (moves / 2);
                    bob += f * ((moves + 1) / 2);
                }
                freq[*it + 1] = f;
                freq[i] = 0;
                all.erase(i);
                all.insert(*it + 1);
                blocked.insert(*it + 1);
                turn = !turn;
                if(blocked.count(i + 1)) {
                    pq.push({freq[i + 1], i + 1});
                    blocked.erase(i + 1);
                }
            }
        }
        cout << alice << " " << bob << '\n';
    }
}