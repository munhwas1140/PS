#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
struct Node {
    int key, hei;
    Node *l, *r;
    Node() : key(0), hei(0), l(nullptr), r(nullptr) {}
};
void insertBST(Node **T, int newKey) {
    Node **p = T;
    Node **q = nullptr;
    stack<Node **> st;
    while((*p) != nullptr) {
        if(newKey == (*p)->key) {
            cout << "i <" << newKey << "> : The key already exists" << '\n';
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
// void deleteBST(Node *T, int deleteKey) {
//     Node *p = T;
//     Node *q = nullptr;
//     stack<Node *> st;

//     while(p != nullptr && deleteKey != p->key) {
//         q = p;
//         st.push(q);
//         if(deleteKey < p->key) p = p->l;
//         else p = p->r;
//     }
    
//     if(p == nullptr) {
//         cout << "d <" << deleteKey << "> : The key does not exist" << '\n';
//         return ;
//     }

//     if(p->l != nullptr && p->r != nullptr) {
//         st.push(p);
//         Node *tempNode = p;
//         if(p->l->hei <= p->r->hei) {
//             p = p->r;
//             while(p->l != nullptr) {
//                 st.push(p);
//                 p = p->l;
//             }
//         } else {
//             p = p->l;
//             while(p->r != nullptr) {
//                 st.push(p);
//                 p = p->r;
//             }
//         }

//         tempNode->key = p->key;
//         q = st.top();
//     } 

//     if(p->l == nullptr && p->r == nullptr) {
//         if(q == nullptr) {
//             T = nullptr;
//         } else if(q->l == p) {
//             q->l = nullptr;
//         } else {
//             q->r = nullptr;
//         }
//     } else {
//         if(p->l != nullptr) {
//             if(q == nullptr) T = T->l;
//             else if(q->l == p) q->l = p->l;
//             else q->r = p->l;
//         } else {
//             if(q == nullptr) T = T->r;
//             else if(q->l == p) q->l = p->r;
//             else q->r = p->r;
//         }
//     }


//     delete p;
//     while(!st.empty()) {
//         q = st.top();
//         st.pop();
//         int lhei = (q->l ? q->l->hei : 0);
//         int rhei = (q->r ? q->r->hei : 0);
//         q->hei = 1 + max(lhei, rhei);
//     }
// }
bool deleteBST(Node *T, int deleteKey) {
    Node *p = T;
    Node *q = nullptr;
    stack<Node *> st;

    while(p != nullptr && deleteKey != p->key) {
        q = p;
        st.push(q);

        if(deleteKey < p->key) p = p->l;
        else p = p->r;
    }

    if(p == nullptr) {
        cout << "d <" << deleteKey << "> : The key does not exist" << '\n';
        return true;
    }

    if(p->l != nullptr && p->r != nullptr) {
        st.push(p);
        Node *tempNode = p;

        if(p->l->hei <= p->r->hei) {
            p = p->r;
            while(p->l != nullptr) {
                st.push(p);
                p = p->l;
            }
        } else {
            p = p->l;
            while(p->r != nullptr) {
                st.push(p);
                p = p->r;
            }
        }
        
        tempNode->key = p->key;
        q = st.top();
    }
    if(p->l == nullptr && p->r == nullptr) {
        if(q == nullptr) return false;
        else if(q->l == p) q->l = nullptr;
        else q->r = nullptr;
    } else {
        if(p->l != nullptr) {
            if(q == nullptr) return false;
            else if(q->l == p) q->l = p->l;
            else q->r = p->l;
        } else {
            if(q == nullptr) return false;
            else if(q->l == p) q->l = p->r;
            else q->r = p->r;
        }
    }
    
    delete p;
    while(!st.empty()) {
        q = st.top();
        st.pop();
        int lhei = (q->l ? q->l->hei : 0);
        int rhei = (q->r ? q->r->hei : 0);
        q->hei = 1 + max(lhei, rhei);
    }
    return true;
}
int height(Node *T) {
    if(T == nullptr) return 0;
    return T->hei;
}
bool noNodes(Node *T) {
    if(T == nullptr) return true;
    return false;
}
void inOrder(Node *node) {
    if(node == nullptr) return ;
    inOrder(node->l);
    cout << node->key << ' ';
    inOrder(node->r);
}
void preOrder(Node *node) {
    if(node == nullptr) return ;
    cout << node->key << ' ';
    preOrder(node->l);
    preOrder(node->r);
}

int main() {
    fastio;
    string str;
    Node *T = nullptr;

    ifstream fin("algo/BST-input.txt");

    while(fin >> str) {
        int key;
        if(str[0] == 'i') {
            fin >> key;
            insertBST(&T, key);
            inOrder(T);
            cout << '\n';
        } else if(str[0] == 'd') {
            fin >> key;
            if(!deleteBST(T, key)) {
                if(T->r) T = T->r;
                else if(T->l) T = T->l;
                else T = nullptr;
            }
            inOrder(T);
            cout << '\n';
        } else {
            key = stoi(str);
        }
    }
    return 0;
}