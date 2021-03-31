#include <iostream>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

struct Edge {
    int from, to, cost;

    Edge(int from, int to, int cost) : from(from), to(to), cost(cost) {};
};

vector<int> p, cnt;

int get(int v) {
    if (p[v] == v) return v;
    return p[v] = get(p[v]);
}

void unite(int x, int y) {
    int a = get(x), b = get(y);
    if (a == b) return;
    if (cnt[a] < cnt[b]) swap(a, b);
    p[b] = a;
    cnt[a] += cnt[b];
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<Edge> e;
    for (int i = 0; i < m; ++i) {
        int from, to, cost;
        cin >> from >> to >> cost;
        --from, --to;
        e.emplace_back(from, to, cost);
    }
    p.resize(n), cnt.resize(n);
    for (int i = 0; i < n; ++i) p[i] = i;
    int mst = 0;
    vector<int> cheap(n, -1);
    int comp = n;
    while (comp > 1) {
        for (int i = 0; i < n; ++i) cheap[i] = -1;
        for (int i = 0; i < m; ++i) {
            int from = e[i].from, to = e[i].to, cost = e[i].cost;
            int s1 = get(from), s2 = get(to);
            if (s1 == s2) continue;
            if (cheap[s1] == -1 || e[cheap[s1]].cost > cost) cheap[s1] = i;
            if (cheap[s2] == -1 || e[cheap[s2]].cost > cost) cheap[s2] = i;
        }

        for (int i = 0; i < n; ++i) {
            int j = cheap[i];
            if(j == -1) continue;
            int from = e[j].from, to = e[j].to, cost = e[j].cost;
            int s1 = get(from), s2 = get(to);
            if(s1 == s2) continue;
            unite(s1, s2);
            mst += cost;
            comp--;
        }
    }
    cout << mst;
}