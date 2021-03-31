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
    int h;

    Node(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
        h = 1;
    }
};

int height(Node *tree) {
    if (tree == nullptr) return 0;
    else return tree->h;
}

int getBalance(Node *N) {
    if (N == nullptr)
        return 0;
    return height(N->left) - height(N->right);
}

Node *leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->h = max(height(x->left), height(x->right)) + 1;
    y->h = max(height(y->left), height(y->right)) + 1;
    return y;
}

Node *rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->h = max(height(y->left), height(y->right)) + 1;
    x->h = max(height(x->left), height(x->right)) + 1;
    return x;
}

Node *Add(Node *tree, int x) {
    //1
    if (tree == nullptr) {
        tree = new Node(x);
        return tree;
    } else if (x < tree->val) {
        tree->left = Add(tree->left, x);
    } else {
        tree->right = Add(tree->right, x);
    }
    //2
    tree->h = 1 + max(height(tree->left), height(tree->right));
    //3
    int balance = getBalance(tree);

    // If this tree becomes unbalanced, then  
    // there are 4 cases  

    // Left Left Case  
    if (balance > 1 && x < tree->left->val)
        return rightRotate(tree);

    // Right Right Case  
    if (balance < -1 && x > tree->right->val)
        return leftRotate(tree);

    // Left Right Case  
    if (balance > 1 && x > tree->left->val) {
        tree->left = leftRotate(tree->left);
        return rightRotate(tree);
    }

    // Right Left Case  
    if (balance < -1 && x < tree->right->val) {
        tree->right = rightRotate(tree->right);
        return leftRotate(tree);
    }
    return tree;
}

Node *minValueNode(Node *tree) {
    Node *current = tree;
    while (current->left != nullptr)
        current = current->left;
    return current;
}


Node *deleteNode(Node *root, int val) {

    // 1: DELETE
    if (root == nullptr)
        return root;
    if (val < root->val)
        root->left = deleteNode(root->left, val);
    else if (val > root->val)
        root->right = deleteNode(root->right, val);

        // if val is same as root's val, then  
        // This is the node to be deleted  
    else {
        // node with only one child or no child  
        if ((root->left == nullptr) || (root->right == nullptr)) {
            Node *temp = nullptr;
            if (root->left != nullptr) temp = root->left;
            else if (root->right != nullptr) temp = root->right;

            // No child case
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else             // One child case
                *root = *temp; // Copy the contents of the non-empty child
            free(temp);
        } else {
            // node with two children
            Node *temp = minValueNode(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right,
                                     temp->val);
        }
    }

    // If the tree had only one node 
    // then return  
    if (root == nullptr)
        return root;

    // 2: HEIGHT
    root->h = 1 + max(height(root->left),
                      height(root->right));

    // 3: BALANCE
    int balance = getBalance(root);

    // Left Left Case  
    if (balance > 1 &&
        getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case  
    if (balance > 1 &&
        getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case  
    if (balance < -1 &&
        getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case  
    if (balance < -1 &&
        getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}


int main() {
    int n;
    cin >> n;
    Node *tree = nullptr;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        tree = Add(tree, x);
    }
}