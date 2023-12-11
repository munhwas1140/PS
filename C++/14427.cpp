#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
vector<int> a;
vector<int> tree;
void init(int node, int s, int e) {
    if(s == e) {
        tree[node] = s;
    } else {
        int m = (s + e) / 2;
        init(node * 2, s, m);
        init(node * 2 + 1, m + 1, e);
        int l = tree[node * 2];
        int r = tree[node * 2 + 1];
        if(a[l] > a[r]) {
            tree[node] = r;
        } else {
            tree[node] = l;
        }
    }
}

void update(int node, int s, int e, int i, int val) {
    if(e < i || s > i) return ;
    if(s == e) {
        a[i] = val;
    } else {
        int m = (s + e) / 2;
        update(node * 2, s, m, i, val);
        update(node * 2 + 1, m + 1, e, i, val);
        int t1 = tree[node * 2];
        int t2 = tree[node * 2 + 1];

        if(a[t1] > a[t2]) {
            tree[node] = t2;
        } else {
            tree[node] = t1;
        }
    }
}

int main() {
    fastio;
    int n; cin >> n;
    a.resize(n + 1);
    int h = int(ceil(log2(n + 1)));
    tree.resize(1 << (h + 1));
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    init(1, 1, n);

    int q; cin >> q;
    while(q--) {
        int t; cin >> t;
        if(t == 1) {
            int i, val;
            cin >> i >> val;
            update(1,1,n,i,val);
        } else if(t == 2) {
            cout << tree[1] << '\n';
        }
    }
    return 0;
}