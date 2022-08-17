#include <bits/stdc++.h>
using namespace std;
vector<long long> tree;
vector<long long> a;

// 구간 합 구하기

void init(int node, int s, int e) {
    if(s == e) {
        tree[node] = a[s];
    } else {
        int m = (s + e) >> 1;
        init(node * 2, s, m);
        init(node * 2 + 1, m + 1, e);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
    return ;
}

void update(int node, int s, int e, int i, long long v) {
    if(i < s || e < i) return ;
    if(s == e) {
        tree[node] = v;
    } else {
        int m = (s + e) >> 1;
        update(node * 2, s, m, i, v);
        update(node * 2 + 1, m + 1, e, i, v);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
}

long long query(int node, int s, int e, int l, int r) {
    if(r < s || e < l) return 0;
    if(l <= s && e <= r) return tree[node];
    int m = (s + e) >> 1;
    long long t1 = query(node * 2, s, m, l, r);
    long long t2 = query(node * 2 + 1, m + 1, e, l, r);
    return t1 + t2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    q += m;

    a.resize(n + 1);
    int h = (int)ceil(log2(n));
    tree.resize(1 << (h + 1));

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    init(1,1,n);

    while(q--) {
        int op, x;
        long long y;
        cin >> op >> x >> y;
        if(op == 1) {
            update(1,1,n,x,y);
        } else {
            cout << query(1,1,n,x,y) << '\n';
        }
        
    }

    return 0;
}