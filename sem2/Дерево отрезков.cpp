#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n;
vector<int> a;
vector<int> t;

void build(int v, int tl, int tr) {
    if (tl == tr) t[v] = a[tl];
    else {
        int tm = (tl + tr) / 2;
        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);
        t[v] = t[2 * v] + t[2 * v + 1];
    }
}

int sum(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    if (tl == l && tr == r) return t[v];
    else {
        int tm = (tl + tr) / 2;
        return sum(2 * v, tl, tm, l, min(tm, r)) + sum(2 * v + 1, tm + 1, tr, max(tm + 1, l), r);
    }
}

void upd(int v, int tl, int tr, int pos, int val){
    if(tl == tr) t[v] = val;
    else{
        int tm = (tl + tr) / 2;
        if(pos <= tm) upd(2 * v, tl, tm, pos, val);
        else upd(2 * v + 1, tm + 1, tr, pos, val);
        t[v] = t[2 * v] + t[2 * v + 1];
    }
}

int main() {
    cin >> n;
    a.resize(n), t.resize(4 * n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    build(1, 0, n - 1);
    cout << sum(1, 0, n - 1, 1, n - 2);
}