// 1. 삽입 : 성공
// 2. 삭제 : 실패
// g++ -std=c++17 환경
// main함수의 File input 위치를 재설정 해주어야합니다.
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
    Node *p = *T;
    Node *q = nullptr;
    while(p != nullptr) {
        if(newKey == p->key) {
            cout << "i " << newKey << " : The key already exists" << '\n';
            return false;
        }
        q = p;
        if(newKey < p->key) p = p->l;
        else p = p->r;
    }
    Node *node = new Node();
    node->key = newKey;
    if(*T == nullptr) *T = node;
    else if(newKey < q->key) q->l = node;
    else q->r = node;
    
    return true;
}
Node *getAVLNode() {
    return new Node();
}
tuple<string ,Node *, Node *> checkBalance(Node **T, int Key) {
    stack<Node *> st;
    Node *p = *T;
    Node *q = nullptr;
    Node *x = nullptr;
    Node *f = nullptr;

    while(true) {
        if(Key == p->key) break;
        st.push(p);
        if(Key < p->key) p = p->l;
        else p = p->r;
    } // Key값의 노드를 찾아가면서 경로의 노드를 스택에 넣는다.
    st.push(p);

    //밸런스체크 이전에 노드를 삽입하거나 삭제하였으므로
    //삽입,삭제노드로부터 루트로 올라가며 노드의 높이와 bf를 갱신
    while(!st.empty()) {
        q = st.top();
        st.pop();

        int lhei = (q->l ? q->l->hei : 0);
        int rhei = (q->r ? q->r->hei : 0);
        q->hei = 1 + max(lhei, rhei);
        q->bf = lhei - rhei;

        if(1 < q->bf || q->bf < -1) { // 스택에서 노드를 꺼내오므로 가장 아래쪽의 불균형 노드
            if(x == nullptr) {
                x = q;
                if(!st.empty()) f = st.top();
            }
        }
    }

    if(x == nullptr) { //불균형 노드가 없는경우 "NO"와 널포인터를 리턴
        return make_tuple("NO", nullptr, nullptr);
    }

    string rotateType;
    if(1 < x->bf) {
        if(x->l && x->l->bf < 0) rotateType = "LR";
        else rotateType = "LL";
    } else {
        if(x->r && x->r->bf > 0) rotateType = "RL";
        else rotateType = "RR";
    }

    return make_tuple(rotateType, x, f);
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
    Node *p = searchBST(root, deleteKey);
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
void updatehei(Node *node) {
    if(!node) return;
    updatehei(node->l);
    updatehei(node->r);

    int lhei = (node->l ? node->l->hei : 0);
    int rhei = (node->r ? node->r->hei : 0);
    node->hei = max(lhei, rhei) + 1;
    node->bf = lhei - rhei;
}
void rotateTree(Node **T, string rotateType, Node *p, Node *q) {
    Node *a, *b, *c;
    if(rotateType == "LL") { // LL rotation
        a = p;
        b = p->l;
        a->l = b->r;
        b->r = a;
        a->bf = 0;
        b->bf = 0;
    } else if(rotateType == "LR") { // LR rotation
        a = p;
        b = p->l;
        c = b->r;
        b->r = c->l;
        a->l = c->r;
        c->l = b;
        c->r = a;
        b = c;
    } else if(rotateType == "RR") { // RR rotation
        a = p;
        b = p->r;
        a->r = b->l;
        b->l = a;
        a->bf = 0;
        b->bf = 0;
    } else { // RL rotation
        a = p;
        b = p->r;
        c = b->l;
        b->l = c->r;
        a->r = c->l;
        c->r = b;
        c->l = a;
        b = c;
    }
    
    updatehei(b);
    if(q == nullptr) *T = b;
    else {
        if(p == q->l) q->l = b;
        else q->r = b;
        updatehei(q);
    }
}
bool insertAVL(Node **T, int newKey) {
    if(!insertBST(T, newKey)) return false; //newKey값이 이미 트리에 있다면 key already exists출력 후 false리턴

    auto [rotateType, p, q] = checkBalance(T, newKey); //balance check
    // p는 bf가 -1 보다 작거나 1보다 큰 노드, q는 p노드의 부모노드.
    // 그러한 노드가 없다면 rotateType == "NO", 그러한 노드가 있다면 상황에 맞는 로테이션 타입을 반환함.

    cout << rotateType << ' '; //rotateType을 출력
    if(rotateType == "NO") return true; //회전시키지 않아도 되는경우 바로 true반환
    
    rotateTree(T,rotateType, p, q); // 트리를 회전시키는 부분
    return true;
}
void deleteAVL(Node **T, int deleteKey) {
    deleteBST(T, deleteKey);

    // auto [rotateType, p, q] = checkBalance(T, tar->key);
    // cout << rotateType << ' ';
    // if(rotateType != "NO") {
    //     rotateTree(T, rotateType, p, q);
    // }
}
void inOrderBST(Node *node) {
    if(node == nullptr) return ;
    inOrderBST(node->l);
    cout << "(" << node->key << ", " << node->bf << ") ";
    inOrderBST(node->r);
}
int main() {
    fastio;
    char q;
    ifstream fin("algo/AVL-input.txt");

    while(fin >> q) {
        int key;
        if(q == 'i') {
            fin >> key;
            insertAVL(&root, key);
            inOrderBST(root);
            cout << '\n';
        } else if(q == 'd') {
            fin >> key;
            Node *p = searchBST(root, key);
            if(p == nullptr) {
                cout << "d " << key << " : The key does not exist\n"; //key를 찾을 수 없을경우 처리
            } else {
                deleteAVL(&root, key);
            }
            inOrderBST(root);
            cout << '\n';
        }
    }
    return 0;
}