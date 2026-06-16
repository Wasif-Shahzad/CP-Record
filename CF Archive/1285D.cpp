//
// 1285D.cpp
// Created by wasifshahzad on 03/27/26 at 12:43:12.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

/*
if we set ith bit in x, then we reduce space to those who don't have it set
else we reduce space to those who have it set
*/

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

    int solve(Node* cur, int i) {
        if(i < 0) return 0;
        if(cur->children[0] != nullptr && cur->children[1] != nullptr) {
            int left = solve(cur->children[0], i - 1);
            int right = solve(cur->children[1], i - 1);
            return (1 << i) + min(left, right);
        }
        if(cur->children[0] != nullptr) {
            return solve(cur->children[0], i - 1);
        } else if(cur->children[1] != nullptr) {
            return solve(cur->children[1], i - 1);
        }
        return 0;
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

void solve() {
    int n;
    cin >> n;
    BitTrie trie;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        trie.insert(x);
    }
    cout << trie.solve(trie.root, 30) << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}