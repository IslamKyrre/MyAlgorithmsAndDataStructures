#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <list>
#include <stack>
#include <cmath>

using namespace std;


int main() {
    int n, m;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    cin >> m;
    vector<int> y(m);
    for (int i = 0; i < m; ++i) {
        cin >> y[i];
    }
    vector<vector<int>> d(n + 1, vector<int> (m + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if(x[i - 1] == y[j - 1]) d[i][j] = d[i - 1][j - 1] + 1;
            else d[i][j] = max(d[i][j - 1], d[i - 1][j]);
        }
    }
    cout << d[n][m];
}