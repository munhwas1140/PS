// https://cubelover.tistory.com/10?category=203362

#include <bits/stdc++.h>
using namespace std;
struct node {
    node *l, *r, *p;
    int key;
    int cnt;
} *tree;

void Update(node *x) {
    x->cnt = 1;
    if(x->l) x += x->l->cnt;
    if(x->r) x += x->r->cnt;
}

void Rotate(node *x) {
    node *p = x->p; 
    node *b = nullptr; 
    if(x == p->l) { 
        p->l = b = x->r;
        x->r = p;
    } else {
        p->r = b = x->l;
        x->l = p;
    }
    x->p = p->p; 
    p->p = x;
    if(b) b->p = p;
    if(x->p) {
        if(x->p->l == p) x->p->l = x;
        else x->p->r = x;
    } else tree = x;
    Update(p);
    Update(x);
}

void Splay(node *x) {
    while(x->p) {
        node *p = x->p;
        node *g = p->p;
        if(g) Rotate((x == p->l) == (p == g->l) ? p : x); 
        Rotate(x);
        // zig-zag rotate(x), rotate(x);
        // zig-zig rotate(p), rotate(x)
        // zig rotate(x) 후 종료됨
    }
}

void Insert(int key) {
    node *p = tree;
    node **pp;
    if(!p) {
        node *x = new node;
        tree = x;
        x->l = x->r = x->p = nullptr;
        x->key = key;
        return ;
    }

    while(1) {
        if(key == p->key) {
            return ;
        } else if(key < p->key) {
            if(!p->l) {
                pp = &p->l;
                break;
            }
            p = p->l;
        } else {
            if(!p->r) {
                pp = &p->r;
                break;
            }
            p = p->r;
        }
    }
    node *x = new node;
    *pp = x;
    x->l = x->r = nullptr;
    x->p = p;
    x->key = key;
    Splay(x);
}

bool Find(int key) {
    node *p = tree;
    if(!p) return false;
    while(p) {
        if(key == p->key) {
            break;
        } else if(key < p->key) {
            if(!p->l) break;
            p = p->l;
        } else {
            if(!p->r) break;
            p = p->r;
        }
    }
    Splay(p);
    return key == p->key;
}

void Delete(int key) {
    if(!Find(key)) return ;
    node *root = tree;
    if(root->l) {
        if(root->r) {
            tree = root->l;
            tree->p = nullptr;
            node *x = tree;
            while(x->r) x = x->r;
            x->r = root->r;
            x->r->p = x;
            Splay(x);
            delete root;
            return ;
            // 원래 루트의 왼쪽 서브트리를 루트로 하고
            // 왼쪽 서브트리 맨 오른쪽에 원래 서루트의 오른쪽 서브트리를 붙이고
            // 오른쪽 서브트리를 붙인 노드를 스플레이해서 위로올림 ㅁㅊ
        }
        tree = root->l;
        tree->p = nullptr;
        delete root;
        return ;
    } else if(root->r) {
        tree = root->r;
        tree->p = nullptr;
        delete root;
        return ;
    }
    delete root;
    tree = nullptr;
}

void kth(int k) { // 0-based
    node *x = tree;
    while(1) {
        while(x->l && x->l->cnt > k) x = x->l;
        if(x->l) k -= x->l->cnt;
        if(!k--) break;
        x = x->r;
    }
    Splay(x);
}

int main() {

}