#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <variant>
#include <stack>


using namespace std;

struct Node {
    int depth, out;
    vector<Node *> children;
};


void fixDepth(Node *node) {
    if (!node) return;
    int maxh = 0;
    for (auto child: node->children) {
        fixDepth(child);
        maxh = max(maxh, child->depth);
    }
    node->depth = maxh + 1;
}

void findDistance(Node *node, int alter) {
    if (node == nullptr) return;

    for (int i = 0; i < node->children.size(); i++) {
        int daddy_alter = 0;
        for (int j = 0; j < node->children.size(); ++j) {
            if (j == i) continue;
            daddy_alter = max(daddy_alter, node->children[j]->depth);
        }
        findDistance(node->children[i], max(daddy_alter, alter) + 1);
    }
    int child_h = 0;
    for (auto child: node->children) child_h = max(child_h, child->depth);
    node->out = max(child_h, alter);
}


int main() {
    int n, x, y;
    cin >> n;
    vector<Node> nodes(n);
    for (int i = 0; i < n - 1; ++i) {
        cin >> x >> y;
        nodes[min(x, y)].children.push_back(&nodes[max(x, y)]);
    }
    fixDepth(&nodes[0]);
    findDistance(&nodes[0], 0);
    for (int i = 0; i < n; ++i) {
        cout << nodes[i].out << " ";
    }
}