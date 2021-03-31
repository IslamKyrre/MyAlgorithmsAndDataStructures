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

struct Node {
    string data;
    bool deleted;

    Node(string key) {
        data = key;
        deleted = false;
    }

};


class HashTable {
public:

    int bufferSize;
    int size;
    Node **nodes;

    HashTable() {
        bufferSize = 8;
        size = 0;
        nodes = new Node *[bufferSize];
        for (int i = 0; i < bufferSize; i++)
            nodes[i] = nullptr;
    }

    ~HashTable() {
        for (int i = 0; i < bufferSize; ++i)
            if (nodes[i] != nullptr)
                delete nodes[i];
        delete[] nodes;
    }

    int hash(string key) {
        int hashed = 0;
        for (char c : key) {
            hashed += 31 * c;
            hashed %= bufferSize;
        }
        return hashed;
    }

    bool contains(string key) {
        int hashed = hash(key);
        int i = 0;
        while (nodes[hashed] != nullptr && i < bufferSize) {
            if (!nodes[hashed]->deleted && nodes[hashed]->data == key)
                return true;
            i++;
            hashed += (i * i + i) / 2;
            //hashed += i;
            hashed %= bufferSize;
        }
        return false;
    }

    bool insert(const string &key) {
        if (contains(key))
            return false;

        if (3 * bufferSize <= 4 * (size + 1))
            rehash();

        int hashed = hash(key);
        int i = 0;

        while (i < bufferSize) {
            if (nodes[hashed] == nullptr) {
                nodes[hashed] = new Node(key);
                size++;
                return true;
            } else if (nodes[hashed]->deleted) {
                nodes[hashed]->data = key;
                nodes[hashed]->deleted = false;
                size++;
                return true;
            }
            i++;
            hashed += (i * i + i) / 2;
            //hashed += i;
            hashed %= bufferSize;
        }
        return false;
    }

    bool remove(string key) {
        if (!contains(key))
            return false;

        int hashed = hash(key);
        int i = 0;

        while (i < bufferSize) {
            if (!nodes[hashed]->deleted && nodes[hashed]->data == key) {
                nodes[hashed]->deleted = true;
                size--;
                return true;
            }
            i++;
            hashed += (i * i + i) / 2;
            //hashed += i;
            hashed %= bufferSize;
        }
        return false;
    }


    void rehash() {
        Node **tmp = nodes;
        bufferSize *= 2;
        size = 0;
        nodes = new Node *[bufferSize];

        for (int i = 0; i < bufferSize; i++)
            nodes[i] = nullptr;

        for (int i = 0; i < bufferSize / 2; i++)
            if (tmp[i] != nullptr) {
                if (!tmp[i]->deleted)
                    insert(tmp[i]->data);
                delete tmp[i];
            }

        delete[] tmp;
    }
};


int main() {
    HashTable hashTable;

    while (!cin.eof()) {
        char cmd;
        string str;
        cin >> cmd;
        cin >> str;
        if (str.empty()) break;
        switch (cmd) {
            case '+':
                if (hashTable.insert(str))
                    cout << "OK\n";
                else
                    cout << "FAIL\n";
                break;
            case '-':
                if (hashTable.remove(str))
                    cout << "OK\n";
                else
                    cout << "FAIL\n";
                break;
            case '?':
                if (hashTable.contains(str))
                    cout << "OK\n";
                else
                    cout << "FAIL\n";
                break;
        }
    }
    return 0;
}