#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

int n;
vector<int> tree;
int query(int node, int s, int e, int l, int r) {
    if(s > r || e < l) return 0;
    if(l <= s && e <= r) return tree[node];
    
    int m = (s + e) / 2;
    int t1 = query(node * 2, s, m, l, r);
    int t2 = query(node * 2 + 1, m + 1, e, l, r);
    return max(t1, t2);
}
void update(int node, int s, int e, int idx, int val) {
    if(e < idx || s > idx) return;
    if(s == e) {
        tree[node] = max(tree[node], val);
    } else {
        int m = (s + e) / 2;
        update(node * 2, s, m, idx, val);
        update(node * 2 + 1, m + 1, e, idx, val);
        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }
}
int main() {
    fastio;
    cin >> n;

    int h = (int)ceil(log2(1e6));
    tree.resize(1 << (h + 1));
    for(int i = 0; i < n; i++) {
        int tmp, mx;
        cin >> tmp;
        if(tmp == 1) mx = 0;
        else mx = query(1,1,1e6,1,tmp - 1);
        update(1,1,1e6,tmp,mx + 1);
    }
    cout << tree[1] << '\n';
    return 0;
}