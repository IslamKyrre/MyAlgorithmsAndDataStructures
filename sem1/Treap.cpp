
using namespace std;

struct item {
    int key, prior;
    item *l, *r;

    item() {}

    item(int key, int prior) : key(key), prior(prior), l(nullptr), r(nullptr) {}

};

typedef item *pitem;

int height(pitem a){
    if(!a) return 0;
    return 1 + max(height(a->l), height(a->r));
}


void split(pitem t, int key, pitem &l, pitem &r) {
    if (!t)
        l = r = nullptr;
    else if (key < t->key)
        split(t->l, key, l, t->l), r = t;
    else
        split(t->r, key, t->r, r), l = t;
}

void merge(pitem &t, pitem l, pitem r) {
    if (!l || !r)
        t = l ? l : r;
    else if (l->prior > r->prior)
        merge(l->r, l->r, r), t = l;
    else
        merge(r->l, l, r->l), t = r;
}

void insert(pitem &t, pitem it) {
    if (!t)
        t = it;
    else if (it->prior > t->prior)
        split(t, it->key, it->l, it->r), t = it;
    else
        insert(it->key < t->key ? t->l : t->r, it);
}


void erase(pitem &t, int key) {
    if (t->key == key)
        merge(t, t->l, t->r);
    else
        erase(key < t->key ? t->l : t->r, key);
}


int main() {
    int n, x, y;
    cin >> n;
    auto Treap = new item();
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        pitem it = new item(x, y);
        insert(Treap, it);
    }
    cout << abs(height(Treap));
}