#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int lg2(double x){
    return (int) log2(x);
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<vector<int>> sparse(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        int lg = lg2(n - i);
        sparse[i].resize(lg + 1);
        sparse[i][0] = a[i];
    }

    for (int k = 1; k <= lg2(n); ++k) {
        for (int i = 0; i < n; ++i) {
            if (k >= sparse[i].size()) break;
            sparse[i][k] = min(sparse[i][k - 1], sparse[i + (1 << (k - 1))][k - 1]);
        }
    }

    for (int i = 0; i < m; ++i) {
        int l, r, L;
        cin >> l >> r;
        --l, --r;
        ++r;
        L = r - l;
        int lg = lg2(L);
        cout << min(sparse[l][lg], sparse[r - (1 << lg)][lg]);
    }
    return 0;
}