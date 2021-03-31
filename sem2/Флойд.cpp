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


int main() {
    int n;
    cin >> n;
    int **g = new int *[n];
    for (int i = 0; i < n; ++i) {
        g[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            cin >> g[i][j];
        }
    }
    int **d = new int *[n];
    for (int i = 0; i < n; ++i) {
        d[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            d[i][j] = g[i][j];
        }
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << d[i][j] << " ";
        }
        cout << endl;
        delete[] d[i];
    }
    delete[] d;

}