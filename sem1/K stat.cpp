#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <list>
#include <stack>
 
using namespace std;
 
 
 
int median(vector<int> &a, int l, int r){
    int mid = (l + r) / 2;
 
    if (a[l] > a[r])
        if (a[r] > a[mid])
            return r;
        else
            return mid;
    else if (a[l] > a[mid])
        return l;
    else
        return mid;
}
 
 
 
int partition(vector<int> &a, int l, int r){
    swap(a[r], a[median(a, l, r)]);
    int j = l;
    for(int i = l; i < r; i++)
        if(a[i] < a[r]){
            swap(a[i], a[j]);
            j++;
        }
    swap(a[j], a[r]);
    return j;
}
 
 
 
int kStat(vector<int> &a, int n, int k){
    int p = 0;
    int r = n - 1;
    int q = partition(a, p, r);
    while(q != k){
        if(k < q)
            r = q - 1;
        else
            p = q + 1;
        q = partition(a, p, r);
    }
    return a[q];
}
 
 
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cout << kStat(a, n, k);
}