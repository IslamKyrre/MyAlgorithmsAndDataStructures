#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <list>
#include <stack>
 
using namespace std;
 
void Merge(vector<int> &a, int l, int m, int r) {
    int k1 = l, k2 = m + 1;
    vector<int> temp;
    while (k1 <= m && k2 <= r) {
        if (a[k1] > a[k2]) {
            temp.push_back(a[k2]);
            ++k2;
        } else {
            temp.push_back(a[k1]);
            ++k1;
        }
    }
    while (k1 <= m) {
        temp.push_back(a[k1]);
        ++k1;
    }
    while (k2 <= r) {
        temp.push_back(a[k2]);
        ++k2;
    }
    for (int i = l; i <= r; ++i) a[i] = temp[i - l];
}
 
void MergeSort(vector<int> &a, int l, int r) {
    if (l == r) return;
    int m = (l + r) / 2;
    MergeSort(a, l, m);
    MergeSort(a, m + 1, r);
    Merge(a, l, m, r);
}
 
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    MergeSort(a, 0, n - 1);
    for (auto x: a) cout << x << " ";
}