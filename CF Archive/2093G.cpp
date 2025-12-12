//
// 2093G.cpp
// Created by Wasif on 12/12/25 at 11:43:09.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

class BitTrie{
public:
    struct Node{
        Node* children[2] = {};
        int cnt = 0;
        Node() : children{nullptr, nullptr}, cnt(0) {}
    };
 
    Node *root;
 
    BitTrie() {
        root = new Node();
    }
 
    void insert(int x) {
        Node *cur = root;
        for(int j = 30; j >= 0; j--) {
            bool bit = (1 << j) & x;
            if(cur->children[bit] == nullptr) {
                cur->children[bit] = new Node();
            }
            cur = cur->children[bit];
            cur->cnt++;
        }
    }
 
    void remove(int x) {
        Node *cur = root;
        for(int j = 30; j >= 0; j--) {
            bool bit = (1 << j) & x;
            Node* tmp = cur->children[bit];
            tmp->cnt--;
            if(tmp->cnt == 0) {
                deleteSubtree(tmp);
                cur->children[bit] = nullptr;
                return;
            }
            cur = tmp;
        }
    }
 
    int query(int x) {
        int ans = 0;
        Node *cur = root;
        for(int j = 30; j >= 0; j--) {
            bool bit = (1 << j) & x;
            if(cur->children[!bit]) {
                ans |= (1 << j);
                cur = cur->children[!bit];
            } else {
                cur = cur->children[bit];
            }
        }
        return ans;
    }
 
    ~BitTrie() {
        deleteSubtree(root);
    }
 
private:
    void deleteSubtree(Node* p) {
        if(!p) return;
        deleteSubtree(p->children[0]);
        deleteSubtree(p->children[1]);
        delete p;
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        if(k == 0) {
            cout << 1 << '\n';
            continue;
        }
        int ans = n + 5;
        BitTrie trie;
        int l = -1, r = 0;
        auto check = [&] (int i) -> bool {
            return trie.query(a[i]) >= k;
        };
        for(; r < n; r++) {
            trie.insert(a[r]);
            while(l + 1 < r) {
                // temporary remove l + 1
                trie.remove(a[l + 1]);
                if(check(r)) {
                    l++;
                } else {
                    trie.insert(a[l + 1]);
                    break;
                }
            }
            if(check(r)) ans = min(ans, r - l);
        }
        cout << (ans > n ? -1 : ans) << '\n';
    }
}