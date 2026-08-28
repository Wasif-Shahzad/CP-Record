#include <bits/stdc++.h>
using namespace std;

const int W_MAX = 6e5+1;
int trie[W_MAX][3];
int node_count;
bool stop[W_MAX];

void insert(string& word) {
    int node = 0;
    for(char c: word) {
        if(trie[node][c - 'a'] == 0) {
            trie[node][c - 'a'] = ++node_count;
        }
        node = trie[node][c - 'a'];
    }
    stop[node] = true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        insert(s);
    }
    while(m--) {
        string s;
        cin >> s;
        auto check = [&] (int i, int node, bool f, auto&& self) -> int {
            if(i == (int)s.size()) {
                return stop[node] && f == false;
            }
            bool ans = false;
            for(int j: {0, 1, 2}) {
                if(!trie[node][j]) continue;
                if(!f && s[i] - 'a' != j) continue;
                ans |= self(i + 1, trie[node][j], min(f, (s[i] - 'a') == j), self);
            }
            return ans;
        };
        if(check(0, 0, 1, check)) cout << "YES\n";
        else cout << "NO\n";
    }
}
