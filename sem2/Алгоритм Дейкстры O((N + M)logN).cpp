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

const int inf = 100000000;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; ++i) {
        int from, to, cost;
        cin >> from >> to >> cost;
        g[from].push_back(make_pair(to, cost));
        g[to].push_back(make_pair(from, cost));
    }
    vector<int> d(n, inf);
    int s, f;
    cin >> s >> f;
    d[s] = 0;
    set<pair<int, int>> set;
    set.insert(make_pair(d[s], s));
    while(!set.empty()){
        int v = set.begin()->second;
        set.erase(make_pair(d[v], v));
        for (auto u: g[v]){
            int to = u.first;
            int cost = u.second;
            if(d[v] + cost < d[to]){
                set.erase(make_pair(d[to], to));
                d[to] = d[v] + cost;
                set.insert(make_pair(d[to], to));
            }
        }
    }
    if(d[f] == inf) cout << -1;
    else cout << d[f];
}