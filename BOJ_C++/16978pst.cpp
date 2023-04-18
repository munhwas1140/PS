#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, q;

struct Node {
    Node *l, *r;
    ll v;
    Node() {
        l = r = NULL;
        v = 0;
    }
};

Node *root[101010];
ll a[101010];

void build(Node *node, int s, int e) {
    if(s == e) {
        node->v = a[s];
        return ;
    }
    int m = (s + e) / 2;
    node->l = new Node();
    node->r = new Node();
    build(node->l, s, m);
    build(node->r, m + 1, e);
    node->v = node->l->v + node->r->v;
}

void add(Node *prv, Node *now, int s, int e, int x, int v) {
    if(s == e) {
        now->v = v;
        return ;
    }
    int m = (s + e) / 2;
    if(x <= m) {
        now->l = new Node();
        now->r = prv->r;
        add(prv->l, now->l, s, m, x, v);
    } else {
        now->l = prv->l;
        now->r = new Node();
        add(prv->r, now->r, m + 1, e, x, v);
    }
    now->v = now->l->v + now->r->v;
}

ll query(Node *node, int s, int e, int l, int r) {
    if(r < s || e < l) return 0;
    if(l <= s && e <= r) return node->v;
    int m = (s + e) / 2;
    ll t1 = query(node->l, s, m, l, r);
    ll t2 = query(node->r, m + 1, e, l, r);
    return t1 + t2;
}

int main() {
    fastio;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    root[0] = new Node();
    build(root[0], 1, n);

    cin >> q;
    int qn = 1;

    while(q--) {
        int qq; cin >> qq;
        if(qq == 1) {
            int i, v;
            cin >> i >> v;
            root[qn] = new Node();
            add(root[qn - 1], root[qn], 1, n, i, v);
            qn++;
        } else {
            int k, i, j;
            cin >> k >> i >> j;
            cout << query(root[k], 1, n, i, j) << '\n';
        }
    }

    return 0;
}