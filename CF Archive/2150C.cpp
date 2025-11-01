//
// 2150C.cpp
// Created by Wasif on 09/28/25 at 07:19:01.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

template<class Info, class Tag>
struct LazySegmentTree {
    const int n;
    std::vector<Info> info;
    std::vector<Tag> tag;
    LazySegmentTree(int n) : n(n), info(4 << std::__lg(n)), tag(4 << std::__lg(n)) {}
    LazySegmentTree(std::vector<Info> init) : LazySegmentTree(init.size()) {
        std::function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                info[p] = init[l];
                return;
            }
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m, r);
            pull(p);
        };
        build(1, 0, n);
    }
    inline void pull(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }
    void apply(int p, const Tag &v) {
        info[p].apply(v);
        tag[p].apply(v);
    }
    void push(int p) {
        apply(2 * p, tag[p]);
        apply(2 * p + 1, tag[p]);
        tag[p] = Tag();
    }
    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        push(p);
        if (x < m) modify(2 * p, l, m, x, v);
        else         modify(2 * p + 1, m, r, x, v);
        pull(p);
    }
    void modify(int p, const Info &v) { modify(1, 0, n, p, v); }
    Info rangeQuery(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) return Info();
        if (l >= x && r <= y) return info[p];
        int m = (l + r) / 2;
        push(p);
        return rangeQuery(2*p, l, m, x, y) + rangeQuery(2*p+1, m, r, x, y);
    }
    Info rangeQuery(int l, int r) { return rangeQuery(1, 0, n, l, r); }
    void rangeApply(int p, int l, int r, int x, int y, const Tag &v) {
        if (l >= y || r <= x) return;
        if (l >= x && r <= y) { apply(p, v); return; }
        int m = (l + r) / 2;
        push(p);
        rangeApply(2*p, l, m, x, y, v);
        rangeApply(2*p+1, m, r, x, y, v);
        pull(p);
    }
    void rangeApply(int l, int r, const Tag &v) { rangeApply(1, 0, n, l, r, v); }
    void half(int p, int l, int r) {
        if (info[p].act == 0) return;
        if ((info[p].min + 1)/2 == (info[p].max + 1)/2) {
            apply(p, {-(info[p].min + 1)/2});
            return;
        }
        int m = (l + r) / 2;
        push(p);
        half(2*p, l, m);
        half(2*p+1, m, r);
        pull(p);
    }
    void half() { half(1, 0, n); }
};

struct Tag {
    int v = 0;
    Tag() = default;
    Tag(int _v) : v(_v) {}
    // initialization of values
    // Tag() : empty constructor is a must
    // Tag(all values) : initialize here
    void apply(const Tag &other) {
        // merge two lazy tags
        v += other.v;
    }
};

struct Info {
    int v = -1e17;
    Info() = default;
    Info(int _v) : v(_v) {}
    // initialization of values
    // Info() : empty constructor is a must
    // Info(all values) : initialize here
    Info operator+(const Info &other) {
        // merge two child infos
        return Info(max(v, other.v));
    }
    void apply(const Tag &t) {
        // how tag affects this node
        v += t.v;
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<int> v(n + 1), a(n + 1), b(n + 1), pb(n + 1);
        for(int i = 1; i <= n; i++) {
            cin >> v[i];
        }
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for(int i = 1; i <= n; i++) {
            cin >> b[i];
            pb[b[i]] = i;
        }
        vector<Info> tmp(n + 2);
        tmp[0] = Info(0);
        LazySegmentTree<Info, Tag> seggy(tmp);
        for(int i = 1; i <= n; i++) {
            int j = pb[a[i]];
            // take as bob
            int cur = seggy.rangeQuery(0, j).v;
            int our = seggy.rangeQuery(j, j + 1).v;
            if(cur > our) {
                seggy.modify(j, Info(cur));
            }
            // take as alice, update for all j < i
            seggy.rangeApply(0, j, v[a[i]]);
        }
        int ans = seggy.rangeQuery(0, n + 1).v;
        cout << ans << '\n';
    }
}