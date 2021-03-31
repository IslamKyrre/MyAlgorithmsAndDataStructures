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


int bin_search(int x, vector<int> d) {
    int l = 0, r = d.size() - 1;
    while (l < r - 1) {
        int m = (l + r) / 2;
        if (d[m] <= x) l = m;
        else r = m;
    }
    return r;
}

int main() {
    int n;
    cin >> n;
    vector<int> d(n + 1);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    d[0] = -inf;
    for (int i = 1; i <= n; ++i) {
        d[i] = inf;
    }
    for (int i = 0; i < n; ++i) {
        int j = bin_search(a[i], d);
        if (d[j - 1] < a[i] && a[i] < d[j]) {
            d[j] = a[i];
        }
    }
    int ans = 0;
    while(d[ans] < inf && ans <= n) ans++;
    cout << ans - 1;
}