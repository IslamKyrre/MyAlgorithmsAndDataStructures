#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <list>
#include <stack>
#include <cmath>

#define inf 100000000
using namespace std;

vector<int> m, c;

vector<vector<int>> D;

int d(int n, int w) {
    if (w < 0) return -inf;
    if (n == 0 || w == 0) return 0;
    if(D[n][w])
        return D[n][w];
    int a = d(n - 1, w);
    int b = d(n - 1, w - m[n - 1]) + c[n - 1];
    D[n][w] = max(a, b);
    return max(a, b);
}


int main() {
    int N, W;
    cin >> N >> W;
    D.resize(N + 1, vector<int> (W + 1));
    m.resize(N);
    c.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> m[i];
    }
    for (int j = 0; j < N; ++j) {
        cin >> c[j];
    }
    cout << d(N, W);
}