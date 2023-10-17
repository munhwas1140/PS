#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
struct node {
    int data, hei, sum, maxv, sz;
    node *l ,*r;
    node(int d = 0) : data(d) {
        sum = maxv = d;
        hei = 0;
        sz = 1;
    }
};
int max(int a, int b) {
    if(a < b) return b;
    return a;
}
void insert(node **root, int data) {
    if(*root == nullptr) {
        node *Node = new node(data);
        *root = Node;
        return ;
    }

    if(data < (*root)->data) {
        insert(&(*root)->l, data);
    } else {
        insert(&(*root)->r, data);
    }

    int lv = (*root)->l ? (*root)->l->sum : 0;
    int rv = (*root)->r ? (*root)->r->sum : 0;
    (*root)->sum = lv + rv + (*root)->data;
    
    int lsz = (*root)->l ? (*root)->l->sz : 0;
    int rsz = (*root)->r ? (*root)->r->sz : 0;
    (*root)->sz = lsz + rsz + 1;
    
    int lh = (*root)->l ? (*root)->l->hei : -1;
    int rh = (*root)->r ? (*root)->r->hei : -1;
    (*root)->hei = max(lh, rh) + 1;

    int lmax = (*root)->l ? (*root)->l->maxv : 0;
    int rmax = (*root)->r ? (*root)->r->maxv : 0;
    (*root)->maxv = max(lmax, rmax) + (*root)->data;

}
void preOrder(node *root) {
    if(!root) return ;
    cout << root->data << ' ';
    preOrder(root->l);
    preOrder(root->r);
}
void inOrder(node *root) {
    if(!root) return ;
    inOrder(root->l);
    cout << root->data << ' ';
    inOrder(root->r);
}
void postOrder(node *root) {
    if(!root) return ;
    postOrder(root->l);
    postOrder(root->r);
    cout << root->data << ' ';
}
int size(node *root) {
    return root->sz;
}
int height(node *root) {
    return root->hei;
}
int sumOfWeight(node *root) {
    return root->sum;
}
int maxPathWeight(node *root) {
    return root->maxv;
}
void mirror(node *root) {
    if(!root) return ;
    node *tmp = root->l;
    root->l = root->r;
    root->r = tmp;
    mirror(root->l);
    mirror(root->r);
}
void destruct(node **root) {
    if(!(*root)) return ;
    destruct(&(*root)->l);
    destruct(&(*root)->r);
    delete *root;
    *root = nullptr;
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        node *root = NULL;
        for(int i = 0; i < n; i++) {
            int data; cin >> data;
            insert(&root, data);
        }
        cout << size(root) << '\n';
        cout << height(root) << '\n';
        cout << sumOfWeight(root) << '\n';
        cout << maxPathWeight(root) << '\n';
        mirror(root);
        preOrder(root); cout << '\n';
        inOrder(root); cout << '\n';
        postOrder(root); cout << '\n';
        destruct(&root); 
        if(root == nullptr) cout << 0 << '\n';
        else cout << 1 << '\n';
    }
    return 0;
}