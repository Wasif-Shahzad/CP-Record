#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void solve() {
    int u, target;
    cin >> u >> target;

    // Pruning: The graph is strictly increasing (u + v > u since v > 0)
    if (u > target) {
        cout << "No\n";
        return;
    }
    if (u == target) {
        cout << "Yes\n";
        return;
    }

    queue<int> q;
    q.push(u);

    // Visited array to prevent cycles/redundant work
    // Sized to target + 1 because we never need to explore nodes > target
    vector<bool> visited(target + 1, false);
    visited[u] = true;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (curr == target) {
            cout << "Yes\n";
            return;
        }

        // Iterate over all submasks v of curr
        // The condition (u & v) == v is equivalent to v being a submask of u
        // Loop iterates: curr, submask1, submask2 ... down to lowest bit
        for (int v = curr; v > 0; v = (v - 1) & curr) {
            long long next_node = (long long)curr + v;

            if (next_node <= target && !visited[next_node]) {
                visited[next_node] = true;
                q.push((int)next_node);
            }
        }
    }

    cout << "No\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    if (cin >> q) {
        while (q--) {
            solve();
        }
    }
    return 0;
}