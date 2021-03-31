#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <variant>


using namespace std;

class Heap {
    int size = 0;
    vector<int> a;

    void sift_up(int i) {
        if (i == 0) return;
        if (a[(i - 1) / 2] < a[i]) {
            swap(a[(i - 1) / 2], a[i]);
            sift_up((i - 1) / 2);
        }
    }

    void sift_down(int i) {
        if (2 * i + 1 > size - 1) return;
        if (2 * i + 2 <= size - 1) {
            if (a[i] > a[2 * i + 1] && a[i] > a[2 * i + 2]) return;
            if (a[2 * i + 2] > a[2 * i + 1]) {
                swap(a[i], a[2 * i + 2]);
                sift_down(2 * i + 2);
            } else {
                swap(a[i], a[2 * i + 1]);
                sift_down(2 * i + 1);
            }
        } else {
            if (a[2 * i + 1] < a[i]) {
                return;
            } else {
                swap(a[i], a[2 * i + 1]);
                sift_down(a[2 * i + 1]);
            }
        }
    }


public:

    void insert(int val) {
        ++size;
        a.push_back(val);
        sift_up(size - 1);
    }

    int top() {
        return a[0];
    }

    int extract() {
        int ans = a[0];
        swap(a[0], a[size - 1]);
        --size;
        sift_down(0);
        a.resize(size);
        return ans;
    }

    void print() {
        for (auto x: a) cout << x << " ";
        cout << endl;
    }

    void print(int n) {
        for (int i = 0; i < n; ++i) {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    Heap(int size, vector<int> &val) {
        this->size = size;
        a.resize(size);
        for (int i = 0; i < size; ++i) a[i] = val[i];
        for (int i = size / 2; i >= 0; --i) {
            sift_down(i);
        }
    }

    void heap_sort() {
        while (size) {
            swap(a[0], a[size - 1]);
            --size;
            sift_down(0);
        }
    }
};


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    Heap heap(n, a);
    heap.heap_sort();
    heap.print(n);
}