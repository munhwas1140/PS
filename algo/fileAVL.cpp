#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
struct Node {
    int key, hei, bf;
    Node *l, *r;
    Node() : key(0), hei(1), bf(0), l(nullptr), r(nullptr) {}
};
Node *root;

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

bool insertBST(Node **T, int newKey) {
    Node **p = T;
    Node **q = nullptr;
    stack<Node **> st;
    while((*p) != nullptr) {
        if(newKey == (*p)->key) {
            cout << "i " << newKey << " : The key already exists" << '\n';
            return false;
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
    return true;
}
Node *getNode() {
    return new Node();
}
tuple<string ,Node *, Node *> checkBalance(Node **T, int newKey) {
    Node *f = nullptr;
    Node *a = *T;
    Node *p = *T;
    Node *q = nullptr;

    while(p != nullptr) { //newKey 삽입 위치 q찾음
        if(p->bf != 0) {
            a = p;
            f = q;
        }

        if(newKey < p->key) {
            q = p;
            p = p->l;
        } else if(newKey > p->key) {
            q = p;
            p = p->r;
        } else {
            q = p;
            break;
        }
    }

    // calc BF
    Node *b;
    int d;
    if(newKey < a->key) {
        p = a->r;
        b = p;
        d = -1;
    } else {
        p = a->l;
        b = p;
        d = -1;
    }

    while(p != q) {
        if(newKey < p->key) {
            p->bf = 1;
            p = p->l;
        } else {
            p->bf = -1;
            p = p->r;
        }
    }

    // balanced check
    bool unbalanced = true;
    if(a->bf != 0 || a->bf + d != 0) {
        a->bf = a->bf + d;
        unbalanced = false;
    }

    string rotateType = "NO";

    if(unbalanced) {
        if(d == 1) {
            if(b->bf == 1) rotateType = "LL";
            else rotateType = "LR";
        }
    }
    return ;
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
bool insertAVL(Node **T, int  newKey) {
    if(*T == nullptr) {
        Node *y = getNode();
        y->key = newKey;
        y->l = nullptr;
        y->r = nullptr;
        y->bf = 0;
        *T = y;
        return true;
    }

    bool found = insertBST(T, newKey);
    if(found) return false;

}
void inorderBST(Node *T) {
    if(T == nullptr) return;
    inorderBST(T->l);
    cout << T->key << ' ';
    inorderBST(T->r);
}
int main() {
    fastio;


    return 0;
}