#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <list>
#include <stack>
 
using namespace std;
 
int partition(vector<int> &a, int l, int r) {
    int pi = (l + r) / 2;
    int p = a[pi];
    int i = l, j = r;
    while (i <= j) {
        while (a[i] < p) ++i;
        while (a[j] > p) --j;
        if (i <= j) {
            swap(a[i], a[j]);
            ++i;
            --j;
        }
    }
    return i - 1;
}
 
 
void quicksort(vector<int> &a, int l, int r) {
    if (l == r) return;
    int i = partition(a, l, r);
    quicksort(a, l, i);
    quicksort(a, i + 1, r);
}
 
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    quicksort(a, 0, n - 1);
    for (auto x: a) cout << x << " ";
}