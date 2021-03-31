#include <iostream>
#include <vector>
#include <cmath>
#include <set>

using namespace std;


int main() {
    const int inf = 1e9;
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; ++i) {
        int from, to, cost;
        cin >> from >> to >> cost;
        --from, --to;
        g[from].emplace_back(to, cost);
        g[to].emplace_back(from, cost);
    }
    vector<int> d(n, inf);
    vector<bool> used(n);
    d[0] = 0;
    set<pair<int, int>> set;
    set.insert(make_pair(d[0], 0));
    int mst = 0;
    while (!set.empty()) {
        int v = set.begin()->second;
        set.erase(make_pair(d[v], v));
        used[v] = true;
        mst += d[v];
        for (auto u: g[v]) {
            int to = u.first, cost = u.second;
            if (!used[to] && cost < d[to]) {
                set.erase(make_pair(d[to], to));
                d[to] = cost;
                set.insert(make_pair(d[to], to));
            }
        }
    }
    cout << mst;
}