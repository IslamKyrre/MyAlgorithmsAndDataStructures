#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <variant>
#include <stack>


using namespace std;

int n;

vector<int> out;
struct Node {
    int i, child_cnt;
    vector<Node *> children;
};

void ChildCount(Node *node) {
    int ans = 0;
    for (auto child: node->children) {
        ChildCount(child);
        ans += child->child_cnt + 1;
    }
    node->child_cnt = ans;
}

void sum_to(Node *node, int cnt) {
    int ch = node->child_cnt;
    cnt = cnt - ch + n - ch - 2;
    out[node->i] = cnt;
    for (auto child: node->children) sum_to(child, cnt);
}


int main() {
    int x, y;
    cin >> n;
    vector<Node> nodes(n);
    for (int i = 0; i < n; ++i) {
        nodes[i].i = i;
    }
    vector<int> dist(n);
    out.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        cin >> x >> y;
        int parent = min(x, y), child = max(x, y);
        nodes[parent].children.push_back(&nodes[child]);
        dist[child] = dist[parent] + 1;
        out[0] += dist[child];
    }
    ChildCount(&nodes[0]);
    for (auto child: nodes[0].children) sum_to(child, out[0]);
    for (auto z: out) cout << z << " ";
}