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
 
long long digit(long long M, int i){
    return M % (long long)(pow(10, i)) / (long long)(pow(10, i - 1));
}
 
int main() {
    int n, m = 10, x;
    cin >> n;
    vector<long long> a(n);
    vector<vector<long long>> d(10);
    for (int i = 0; i < n; ++i) {
        cin >> x;
        a[i] = x;
    }
    for (int i = 1; i <= m; ++i) {
        for (int w = 0; w < 10; ++w) {
            d[w].clear();
        }
        for (int j = 0; j < n; ++j) {
            d[digit(a[j], i)].push_back(a[j]);
        }
        a.clear();
        for (int j = 0; j < 10; ++j) {
            for (auto y: d[j]) a.push_back(y);
        }
    }
    for (auto val: a) cout << val << " ";
}