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

class edge{
public:
    int a, b, cost;
    edge(int a, int b, int cost){
        this->a = a;
        this->b = b;
        this->cost = cost;
    }
};


int main() {
    int n, m, from, to, cost;
    cin >> n >> m;
    vector<edge> e;
    for (int i = 0; i < m; ++i) {
        cin >> from >> to >> cost;
        e.push_back(edge(from, to, cost));
        e.push_back(edge(to, from, cost));
    }
    int s, f;
    cin >> s >> f;
    vector<int> d(n, inf);
    d[s] = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < 2 * m; ++j) {
            from = e[j].a, to = e[j].b, cost = e[j].cost;
            if(d[from] < inf) d[to] = min(d[to], d[from] + cost);
        }
    }
    if(d[f] != inf) cout << d[f] << " ";
    else cout << -1;
}