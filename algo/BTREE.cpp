#include <bits/stdc++.h>
using namespace std;
struct Node {
    int n;
    int K[6];
    Node *P[6];
    Node () {
        n = 0;
        for(int i = 0; i < 6; i++) {
            K[i] = 0;
            P[i] = nullptr;
        }
    }
}*root;

Node* getNode() {
    return new Node();
}

pair<bool, stack<Node *>> searchPath(Node *T, int m, int key, stack<Node *> st) {
    Node *x = T;
    int i;
    do {
        i = 1;
        while(i <= x->n && key > x->K[i]) i++;

        st.push(x);
        if(i <= x->n && key == x->K[i]) {
            return make_pair(true, st);
        }
    } while((x = x->P[i - 1]) != nullptr);

    return make_pair(false,st);
}

void insertKey(Node *T, int m, Node *x, Node *y, int newKey) {
    int i = x->n;
    while(i >= 1 && newKey < x->K[i]) {
        x->K[i + 1] = x->K[i];
        x->P[i + 1] = x->P[i];
        i--;
    }

    x->K[i + 1] = newKey;
    x->P[i + 1] = y;
    x->n++;
}

Node* copyNode(Node *x) {
    Node *tmp = new Node();
    tmp->n = x->n;
    for(int i = 0; i < 6; i++) {
        tmp->K[i] = x->K[i];
        tmp->P[i] = x->P[i];
    }
    return tmp;
}
void printNode(Node* tmp) {
    cout << "size = " << tmp->n << '\n';
    for(int i = 1; i <= tmp->n; i++) {
        cout << tmp->K[i] << ' ';
    }
    cout << '\n';
}
pair<int, Node *> splitNode(Node *T, int m, Node *x, Node *y, int newKey) {
    Node* tempNode = copyNode(x);
    insertKey(T, m, tempNode, y, newKey);
    
    int centerKey = tempNode->K[tempNode->n / 2 + 1];

    x->n = 0;
    int i = 1;
    while(tempNode->K[i] < centerKey) {
        x->K[i] = tempNode->K[i];
        x->P[i - 1] = tempNode->P[i - 1];
        i++;
        x->n++;
    }
    x->P[i - 1] = tempNode->P[i - 1];

    Node* newNode = getNode();
    i++;
    while(i <= tempNode->n) {
        newNode->K[newNode->n + 1] = tempNode->K[i];
        newNode->P[newNode->n] = tempNode->P[i - 1];
        i++;
        newNode->n++;
    }

    newNode->P[newNode->n] = tempNode->P[i - 1];
    return make_pair(centerKey, newNode);
}

void insertBT(Node **T, int m, int newKey) {
    if(*T == nullptr) {
        *T = getNode();
        (*T)->K[1] = newKey;
        (*T)->n = 1;
        return ;
    }
    stack<Node *> st;
    auto [found, stack] = searchPath(*T, m, newKey, st);
    if(found) {
        cout << "i " << newKey << " : The Key already exists" << '\n';
        return ;
    }
    bool finished = false;
    Node* x = stack.top();
    stack.pop();
    Node *y = nullptr;
    do {
        if(x->n < m - 1) {
            insertKey(*T, m, x, y, newKey);
            finished = true;
        } else {
            auto [tnewKey, ty] = splitNode(*T, m, x, y, newKey);
            newKey = tnewKey;
            y = ty;
            if(!stack.empty()) {
                x = stack.top();
                stack.pop();
            } else {
                *T = getNode();
                (*T)->n = 1;
                (*T)->K[1] = newKey;
                (*T)->P[0] = x;
                (*T)->P[1] = y;
                finished = true;
            }
        }
    } while(!finished);
}


void inorderBT(Node *T, int m) {
    if(T == nullptr) return ;

    for(int i = 0; i <= T->n; i++) {
        inorderBT(T->P[i], m);
        if(i != T->n) cout << T->K[i + 1] << ' ';
    }
}

int main() {
    
    while(true) {
        char q; int key;
        cin >> q >> key;
        insertBT(&root, 3, key);
        inorderBT(root, 3);
        cout << '\n';
    }
    
    return 0;
}