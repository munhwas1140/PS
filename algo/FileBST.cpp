#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
struct Node {
    int key, hei;
    Node *l, *r;
    Node() : key(0), hei(0), l(nullptr), r(nullptr) {}
};

Node *root;

Node *getNode() {
    return new Node();
}

Node *searchBST(Node *T, int searchKey) {
    Node *p = T;
    if(p == nullptr) return nullptr;
    if(searchKey == p->key) return p;
    if(searchKey > p->key) return searchBST(p->r, searchKey);
    else return searchBST(p->l, searchKey);
}

Node *searchParent(Node *T, int searchKey) {
    Node *q = nullptr;
    Node *p = T;
    while(p != nullptr) {
        if(searchKey == p->key) return q;
        q = p;
        if(searchKey < p->key) p = p->l;
        else p = p->r;
    }
    return nullptr;
}

void insertBST(Node **T, int newKey) {
    Node **p = T;
    Node **q = nullptr;
    stack<Node **> st;
    while((*p) != nullptr) {
        if(newKey == (*p)->key) {
            cout << "i " << newKey << " : The key already exists" << '\n';
            return ;
        }
        q = p;
        st.push(q);
        if(newKey < (*p)->key) p = &((*p)->l);
        else p = &((*p)->r);
    }
    Node* node = new Node();
    node->key = newKey;
    if(*T == nullptr) *T = node;
    else if(newKey < (*q)->key) (*q)->l = node;
    else (*q)->r = node;
    
    while(!st.empty()) {
        q = st.top();
        st.pop();
        int lhei = ((*q)->l ? (*q)->l->hei : 0);
        int rhei = ((*q)->r ? (*q)->r->hei : 0);
        (*q)->hei = 1 + max(lhei, rhei);
    }
}

int height(Node *p) {
    if(p == nullptr) return 0;
    return p->hei;
}
Node *maxNode(Node *p) {
    while(p->r) {
        p = p->r;
    }
    return p;
}
Node *minNode(Node *p) {
    while(p->l) {
        p = p->l;
    }
    return p;
}
int noNodes(Node *p) {
    if(p == nullptr) return 0;
    int ret = 1;
    ret += noNodes(p->l) + noNodes(p->r);
    return ret;
}
void deleteBST(Node **T, int deleteKey) {
    Node *p =searchBST(root, deleteKey);
    Node *q = searchParent(root, deleteKey);

    if(p == root) { //루트를 제거해야 할 경우
        if(p->l && p->r) { //차수가 2일떄
            Node *r = maxNode(p->l); //무조건 왼쪽 maxNode를 루트로 바꿈
            Node *rq = searchParent(root, r->key);
            if(r == root->l) { //r이 루트의 왼쪽 자식일 경우
                r->r = root->r;
            } else {
                rq->r = r->l;
                r->l = root->l;
                r->r = root->r;
            }
            *T = r;
        } else if(p->l == nullptr && p->r == nullptr) {
            *T = nullptr;
            return ;
        } else {
            if(p->l) *T = (*T)->l;
            else *T = (*T)->r;
        }
        return ;
    }

    if(p->l == nullptr && p->r == nullptr) { //차수 0
        if(q->l == p) q->l = nullptr;
        else q->r = nullptr;
    } else if(p->l != nullptr && p->r != nullptr) { //차수 2
        Node *r;
        bool flag; // false -> left, true -> right
        if(height(p->l) > height(p->r)) {
            r = maxNode(p->l);
            flag = false;
        } else if(height(p->l) < height(p->r)) {
            r = minNode(p->r);
            flag = true;
        } else {
            if(noNodes(p->l) >= noNodes(p->r)) {
                r = maxNode(p->l);
                flag = false;
            } else {
                r = minNode(p->r);
                flag= true;
            }
        }
        
        Node *rq = searchParent(root, r->key);
        //재귀처리보다 그냥 노드r로 바로 대체
        if(flag == false) {
            rq->r = r->l;
            r->l = p->l;
            r->r = p->r;
            if(q->l == p) q->l = r;
            else q->r = r;
        } else { 
            rq->l = r->r;
            r->l = p->l;
            r->r = p->r;
            if(q->l == p) q->l = r;
            else q->r = r;
        }
    } else { //차수 1
        if(p->l != nullptr) {
            if(q->l == p) q->l = p->l;
            else q->r = p->l;
        } else {
            if(q->l == p) q->l = p->r;
            else q->r = p->r;
        }
    }
    return ;
}
void inOrderBST(Node *node) {
    if(node == nullptr) return ;
    inOrderBST(node->l);
    cout << node->key << ' ';
    inOrderBST(node->r);
}
void preOrderBST(Node* node) {
    if(node == nullptr) return;
    cout << node->key << ' ';
    preOrderBST(node->l);
    preOrderBST(node->r);
}
int main() {
    fastio;
    char q;

    ifstream fin("algo/BST-input.txt");

    while(fin >> q) {
        int key;
        if(q == 'i') {
            fin >> key;
            insertBST(&root, key);
            inOrderBST(root);
            cout << '\n';
        } else if(q == 'd') {
            fin >> key;
            Node *p = searchBST(root, key);
            if(p == nullptr) {
                cout << "d " << key << " : The key does not exist\n"; //key를 찾을 수 없을경우 처리
            } else {
                deleteBST(&root, key);
            }
            inOrderBST(root);
            cout << '\n';
        }
    }
    return 0;
}