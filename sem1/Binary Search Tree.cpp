#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <list>
#include <stack>
#include <cmath>

using namespace std;

class Node {
public:
    int val;
    Node *left;
    Node *right;

    Node(int val) {
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};

class Node *Add(int x, Node *tree) {
    if (tree == nullptr) {
        tree = new Node(x);
    } else if (x < tree->val) {
        tree->left = Add(x, tree->left);
    } else
        tree->right = Add(x, tree->right);
    return (tree);
}

void in_order(Node *tree) {
    if (tree != nullptr) {
        in_order(tree->left);
        cout << tree->val << " ";
        in_order(tree->right);
    }
}

void pre_order(Node *tree) {
    if (tree != nullptr) {
        cout << tree->val << " ";
        pre_order(tree->left);
        pre_order(tree->right);
    }
}

void post_order(Node *tree) {
    if (tree != nullptr) {
        post_order(tree->left);
        post_order(tree->right);
        cout << tree->val << " ";
    }
}

void in_order2(Node *tree) {
    stack<Node *> s;
    Node *curr = tree;

    while (curr != nullptr || !s.empty()) {
        while (curr != nullptr) {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout << curr->val << " ";
        curr = curr->right;
    }
}

void pre_order2(Node *tree) {
    stack<Node *> s;
    s.push(tree);
    while (!s.empty()) {
        Node *curr = s.top();
        s.pop();
        if (curr != nullptr) {
            cout << curr->val << " ";
            s.push(curr->right);
            s.push(curr->left);
        }
    }
}

void post_order2(Node *tree) {
    stack<Node *> s1, s2;
    s1.push(tree);
    Node *curr;
    while (!s1.empty()) {
        curr = s1.top();
        s1.pop();
        s2.push(curr);
        if (curr->left)
            s1.push(curr->left);
        if (curr->right)
            s1.push(curr->right);
    }
    while (!s2.empty()) {
        curr = s2.top();
        s2.pop();
        cout << curr->val << " ";
    }
}

void level_order(class Node *tree){
    queue<Node *> q;
    q.push(tree);
    while(!q.empty()){
        Node *curr = q.front();
        q.pop();
        cout << curr->val << " ";
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
}


int main() {
    int n;
    cin >> n;
    Node *tree = nullptr;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        tree = Add(x, tree);
    }
    level_order(tree);
}