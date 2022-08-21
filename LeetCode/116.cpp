#include <bits/stdc++.h>
using namespace std;

// Popilating Next Right Pointers in Each Node

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        vector<Node *> tree(1 << 12);
        go(1, root, tree);
        go2(1, root, tree, 1);
        return root;
    }
    
    void go(int node, Node *root, vector<Node *> &tree) {
        if(!root) return ;
        tree[node] = root;
        go(node * 2, root->left, tree);
        go(node * 2 + 1, root->right, tree);
    }
    
    void go2(int node, Node *root, vector<Node *> &tree, int depth) {
        if(!root) return ;
        if(node + 1 < (1 << depth)) {
            root->next = tree[node + 1];
        }
        go2(node * 2, root->left, tree, depth + 1);
        go2(node * 2 + 1, root->right, tree, depth + 1);
    }
};