//
// 2121G.cpp
// Created by Wasif on 12/03/25 at 20:34:56.
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
    // initialization of values
    // Tag() : empty constructor is a must
    // Tag(all values) : initialize here
    int sum = 0, freq = 0;
    Tag() = default;
    Tag(int s, int f) : sum(s), freq(f) {}
    void apply(const Tag &other) {
        // merge two lazy tags
        sum += other.sum;
        freq += other.freq;
    }
};

struct Info {
    // initialization of values
    // Info() : empty constructor is a must
    // Info(all values) : initialize here
    int sum = 0, freq = 0, len = 0;
    Info() = default;
    Info(int s, int f, int l) : sum(s), freq(f), len(l) {}
    Info operator+(const Info &other) {
        // merge two child infos
        return Info(sum + other.sum, freq + other.freq, len + other.len);
    }
    void apply(const Tag &t) {
        // how tag affects this node
        sum += t.sum * len;
        freq += t.freq * len;
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
        string s;
        cin >> s;
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            ans += i * (n - i + 1);
        }
        vector<Info> tmp(2 * n + 2, Info(0, 0, 1));
        tmp[n] = {0, 1, 1};
        LazySegmentTree<Info, Tag> seggy(tmp);
        int cur = 0;
        for(int i = 0; i < n; i++) {
            cur += (s[i] == '1' ? 1 : -1);
            // for all smaller elems
            int m = cur + n;
            auto [small_sum, small_freq, len] = seggy.rangeQuery(0, m);
            int here = small_freq * cur - small_sum;
            ans += here;
            auto [large_sum, large_freq, len_] = seggy.rangeQuery(m, 2 * n + 1);
            here = large_sum - large_freq * cur;
            ans += here;
            seggy.rangeApply(m, m + 1, {cur, 1});
        }
        ans /= 2;
        cout << ans << '\n';
    }
}