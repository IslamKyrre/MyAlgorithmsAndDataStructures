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

class edge {
public:
    int from, to, cost;

    edge(int from, int to, int cost) : from(from), to(to), cost(cost) {};
};

int cmp(edge e1, edge e2) {
    return e1.cost < e2.cost;
}

vector<int> p, cnt;

int get(int v) {
    return v == p[v] ? v : p[v] = get(p[v]);
}

void unite(int v, int u) {
    int a = get(v), b = get(u);
    if(a == b) return;
    if (cnt[a] < cnt[b]) swap(a, b);
    p[b] = a;
    cnt[a] += cnt[b];
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<edge> e;
    for (int i = 0; i < m; ++i) {
        int from, to, cost;
        cin >> from >> to >> cost;
        --from, --to;
        e.emplace_back(from, to, cost);
    }
    p.resize(n);
    cnt.resize(n);
    for (int i = 0; i < n; ++i) {
        p[i] = i;
    }
    int mst = 0;
    sort(e.begin(), e.end(), cmp);
    for (int i = 0; i < m; ++i) {
        int v = e[i].from, u = e[i].to, cost = e[i].cost;
        if(get(v) != get(u)) {
            mst += cost;
            unite(v, u);
        }
    }
    cout << mst;
}