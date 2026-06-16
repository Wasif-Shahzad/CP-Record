//
// 1895D.cpp
// Created by wasifshahzad on 06/14/26 at 12:26:56.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n - 1);
    for(int i = 0; i < n - 1; i++) {
        cin >> a[i];
    }
    BitTrie trie;
    vector<int> pref(n, 0);
    for(int i = 1; i < n; i++) {
        pref[i] = pref[i - 1] ^ a[i - 1];
        trie.insert(pref[i]);
    }
    vector<int> b(n);
    for(int i = 0; i < n; i++) {
        int res = trie.query(i);
        if(res < n) {
            b[0] = i;
            break;
        }
    }
    for(int i = 1; i < n; i++) {
        b[i] = pref[i] ^ b[0];
    }
    for(int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    cout << '\n';
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