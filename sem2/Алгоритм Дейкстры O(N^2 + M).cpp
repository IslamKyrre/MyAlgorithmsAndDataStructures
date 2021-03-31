#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <list>
#include <stack>
#include <cmath>
#include <set>

using namespace std;

const int inf = 1e9;

int main() {
    int n, m, from, to, cost;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; ++i) {
        cin >> from >> to >> cost;
        g[from].push_back(make_pair(to, cost));
        g[to].push_back(make_pair(from, cost));
    }
    int s, f;
    cin >> s >> f;
    vector<int> d(n, inf);
    vector<bool> used(n);
    d[s] = 0;
    for (int i = 0; i < n; ++i) {
        int val = inf, v = -1;
        for (int j = 0; j < n; ++j)
            if(!used[j] && d[j] < val) val = d[j], v = j;
        if(val == inf) break;
        used[v] = true;
        for (auto u: g[v]){
            to = u.first;
            cost = u.second;
            d[to] = min(d[to], d[v] + cost);
        }
    }
    if(d[f] != inf) cout << d[f] << " ";
    else cout << -1;
}