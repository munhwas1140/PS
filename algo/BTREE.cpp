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

void deleteKey(Node *T, int m, Node *x, int oldKey) {
    int i = 1;
    while(oldKey > x->K[i]) i++;
    while(i <= x->n) {
        x->K[i] = x->K[i + 1];
        x->P[i] = x->P[i + 1];
        i++;
    }
    x->n--;
}
int bestSibling(Node *T, int m, Node *x, Node *y) {
    int i = 0;
    while(y->P[i] != x) i++;
    
    int ret;
    if(i == 0) ret = i + 1;
    else if(i == y->n) ret = i - 1;
    else if(y->P[i - 1]->n >= y->P[i + 1]->n) ret = i - 1;
    else ret = i + 1;
    return ret;
}

void redistributeKey(Node *T, int m, Node *x, Node *y, int bestSibling) {
    int i = 0;
    while(y->P[i] != x) i++;

    Node *bestNode = y->P[bestSibling];
    if(bestSibling < i) {
        int lastKey = bestNode->K[bestNode->n];
        insertKey(T, m, x, nullptr, y->K[i]);
        x->P[1] = x->P[0];
        x->P[0] = bestNode->P[bestNode->n];
        bestNode->P[bestNode->n] = nullptr;
        deleteKey(T, m, bestNode, lastKey);
        y->K[i] = lastKey;
    } else {
        int firstKey = bestNode->K[1];
        insertKey(T, m, x, nullptr, y->K[i + 1]);
        x->P[x->n] = bestNode->P[0];
        bestNode->P[0] = bestNode->P[1];
        deleteKey(T, m, bestNode, firstKey);
        y->K[i + 1] = firstKey;
    }
}
void mergeNode(Node *T, int m, Node *x, Node *y, int bestSibling) {
    int i = 0;
    while(y->P[i] != x) i++;

    Node *bestNode = y->P[bestSibling];
    if(bestSibling > i) {
        swap(bestSibling, i);
        swap(bestNode, x);
    }

    bestNode->K[bestNode->n + 1] = y->K[i];
    bestNode->n++;

    int j = 1;
    while(j <= x->n) {
        bestNode->K[bestNode->n + 1] = x->K[j];
        bestNode->P[bestNode->n] = x->P[j - 1];
        bestNode->n++;
        j++;
    }

    bestNode->P[bestNode->n] = x->P[x->n];
    deleteKey(T, m, y, y->K[i]);
    delete x;
}
bool isRoot(Node *x) {
    if(x == root) return true;
    return false;
}
bool isTerminalNode(Node *x) {
    for(int i = 0; i <= x->n; i++) {
        if(x->P[i]) return false;
    }
    return true;
}
void deleteBT(Node **T, int m, int oldKey) {
    stack<Node *> st;
    auto [found, stack] = searchPath(*T, m, oldKey, st);
    if(!found) {
        cout << "d " << oldKey << " : The key does not exist" << '\n';
        return ;
    }

    Node *x = stack.top();
    stack.pop();
    Node *y = nullptr;

    // if(!isTerminalNode(x)) { //내부노드에서발견
    //     Node *internalNode = x;
    //     int i = 0;
    //     for(int j = 1; j <= internalNode->n; j++) {
    //         if(oldKey == internalNode->K[j]) {
    //             i = j;
    //             break;
    //         }
    //     }

    //     stack.push(x);

    //     auto [found2, stack2] = searchPath(x->P[i], m, x->K[i], stack);
    //     int tmp = internalNode->K[i];
    //     internalNode->K[i] = x->K[1];
    //     x->K[1] = tmp;
    //     stack = stack2;
    // }


    bool finished = false;
    deleteKey(*T, m, x, oldKey);
    if(!stack.empty()) {
        y = stack.top();
        stack.pop();
    }

    do {
        if(isRoot(x) || x->n >= int(ceil(m / 2)) - 1) {
            finished = true;
        } else {
            int BS = bestSibling(*T, m, x, y);

            if(y->P[BS]->n > int(ceil(m / 2)) - 1) {
                redistributeKey(*T, m, x, y, BS);
                finished = true;
            } else {
                mergeNode(*T, m, x, y, BS);
                x = y;
                if(!stack.empty()) {
                    y = stack.top();
                    stack.pop();
                } else finished = true;
            }
        }
    } while(!finished);

    if(y != nullptr && y->n == 0) {
        *T = y->P[0];
        delete y;
    }


}
int main() {
    
    while(true) {
        char q; int key;
        cin >> q >> key;

        if(q == 'i') {
            insertBT(&root, 3, key);
        } else {
            deleteBT(&root, 3, key);
        }
        inorderBT(root, 3);
        cout << '\n';
    }
    
    return 0;
}