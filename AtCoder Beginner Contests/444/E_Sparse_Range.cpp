#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) (int)a.size()
#define V vector
#define ff first
#define ss second
#define rep(i, a, n) for (int i = a; i < n; i++)
#define rev(i, a, n) for(int i = a; i > n; i--)
#define out(a) cout << a << "\n"
#define outv(a) rep(i, 0, (int)a.size()) cout << a[i] << " "; cout << endl;
#define in(a) for(auto &i: a) cin >> i;
#define pb push_back
#define pii pair<int, int>
const int mod1 = 1e9+7, mod2 = 998244353;

struct DynamicSegmentTree {
    struct Node {
        int val;
        Node *left = nullptr, *right = nullptr;
        Node(int v) : val(v) {}
    };

    Node* root = nullptr;
    int size;
    const int INF = 1e10;

    DynamicSegmentTree(int n) : size(n) {}

    void update(Node*& node, int l, int r, int idx, int val) {
        if (!node) node = new Node(INF);
        if (l == r) {
            node->val = val;
            return;
        }
        int mid = l + (r - l) / 2;
        if (idx <= mid) update(node->left, l, mid, idx, val);
        else update(node->right, mid + 1, r, idx, val);
        
        int leftVal = node->left ? node->left->val : INF;
        int rightVal = node->right ? node->right->val : INF;
        node->val = min(leftVal, rightVal);
    }

    int query(Node* node, int l, int r, int ql, int qr) {
        if (!node || ql > r || qr < l) return INF;
        if (ql <= l && r <= qr) return node->val;
        int mid = l + (r - l) / 2;
        return min(query(node->left, l, mid, ql, qr),
                   query(node->right, mid + 1, r, ql, qr));
    }

    void update(int idx, int val) {
        update(root, 0, size - 1, idx, val);
    }

    int query(int l, int r) {
        return query(root, 0, size - 1, l, r);
    }
};

void solve(){
    int n, d;
    cin >> n >> d;
    V<int> a(n); in(a);
    int ans = 0;
    int N = 1e9 + 1;
    DynamicSegmentTree seggy(N);
    V<int> has(n, -1);
    rev(i, n - 1, -1) {
        int l = a[i] - d + 1, r = a[i] + d - 1;
        int j = seggy.query(l, r);
        if(j != 1e10) {
            has[j] = max(has[j], i);
        }
        seggy.update(a[i], i);
    }
    rep(i, 0, n) {
        if(i > 0) has[i] = max(has[i], has[i - 1]);
        ans += i - has[i];
    }
    out(ans);
}

signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}