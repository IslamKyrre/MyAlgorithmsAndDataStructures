#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <variant>
#include <stack>


using namespace std;

int n, l;
vector<vector<int> > g;
vector<int> tin, tout;
int timer;
vector<vector<int> > up;

void dfs(int v, int p = 0) {
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i - 1]][i - 1];
    for (size_t i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if (to != p)
            dfs(to, v);
    }
    tout[v] = ++timer;
}

bool upper(int a, int b) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca(int a, int b) {
    if (upper(a, b)) return a;
    if (upper(b, a)) return b;
    for (int i = l; i >= 0; --i)
        if (!upper(up[a][i], b))
            a = up[a][i];
    return up[a][0];
}

int main() {
    cin >> n;
    g.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int f, t;
        cin >> f >> t;
        g[f].push_back(t);
        g[t].push_back(f);
    }

    tin.resize(n), tout.resize(n), up.resize(n);
    l = 1;
    while ((1 << l) <= n) ++l;
    for (int i = 0; i < n; ++i) up[i].resize(l + 1);
    dfs(0);
    int a, b;
    cin >> a >> b;
    cout << lca(a, b);
}