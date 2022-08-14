#include <bits/stdc++.h>
using namespace std;

struct node {
    node *l;
    node *r;
    node *p;
    int cnt;
    int key;
} *tree;

void update(node *x) {
    x->cnt = 1;
    if(x->l) x->cnt += x->l->cnt;
    if(x->r) x->cnt += x->r->cnt;
}

void rotate(node *x) {
    if(!x->p) return;
    node *p = x->p;
    node *q;
    if(p->l == x) {
        p->l = q = x->r;
        x->r = p;
    } else {
        p->r = q = x->l;
        x->l = p;
    }
    if(q) q->p = p;
    x->p = q = p->p;
    p->p = x;
    if(!q) tree = x;
    else if(q->l == p) q->l = x;
    else if(q->r == p) q->r = x;
    update(p);
    update(x);
}

void splay(node *x, node *g = nullptr) {
    node *y;
    while(x->p != g) {
        node *p = x->p;
        if(p->p == g) {
            rotate(x) break;
        }
        auto pp = p->p;
        if((p->l == x) == (pp->l == p)) {
            rotate(p); rotate(x);
        } else {
            rotate(x); rotate(x);
        }
    }
    if(!g) root = x;
}

void insert(int key) {
    node *p = tree;
    node **pp;
    if(!p) {
        node *x = new node;
        tree = x;
        x->l = x->r = x->p = NULL;
        x->key = key; return;
    }
    while(1) {
        if(key == p->key) return ;
        if(key < p->key) {
            if(!p->l) {
                pp = &p->l; break;
            }
            p = p->l;
        } else {
            if(!p->r) {
                pp = &p->r; break;
            }
            p = p->r;
        }
    }
    node *x = new node;
    *pp = x;
    x->l = x->r = NULL;
    x->p = p;
    x->key = key;
    splay(x);
}

bool find(int key) {
    node *p = tree;
    if(!p) return false;
    while(p) {
        if(key == p->key) break;
        if(key < p->key) {
            if(!p->l) break;
            p = p->l;
        } else {
            if(!p->r) break;
            p = p->r;
        }
    }
    splay(p);
    return key == p->key;
}

void Delete(int key) {
    if(!find(key)) return ;
    node *p = tree;
    if(p->l && p->r) {
        tree = p->l;
        tree->p = NULL;

        node *x = tree;
        while(x->r) x = x->r;
        x->r = p->r;
        p->r->p = x;
        delete p;
        return ;
    }
}

void kth(int k) {
    node *x = tree;
    while(1) {
        while(x->l && x->l->cnt > k) x = x->l;
        if(x->l) k -= x->l->cnt;
        if(!k--) break;
        x = x->r;
    }
    splay(x);
}

void ino(node *x) {
    if(!x) return;
    ino(x->l);
    cout << x->key << ' ';
    ino(x->r);
}   

node* gather(int s, int e) {
    kth(e+1);
    auto tmp = root;
    key(s-1);
    splay(tmp, root);
    return root->r->l;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int q = m + k;
    for(int i = 0; i < n; i++) {
        long long t; 
        cin >> t;
        insert(t);
    }
    while(q--) {
        
    }
}