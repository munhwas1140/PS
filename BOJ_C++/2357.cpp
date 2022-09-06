#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
int n, m;
vector<int> a;
vector<pair<int,int>> tree;
void init(int node, int l, int r) {
    if(l == r) {
        tree[node] = make_pair(a[l], a[l]);
    } else {
        int m = (l + r) / 2;
        init(node * 2, l, m);
        init(node * 2 + 1, m + 1, r);
        tree[node].first = min(tree[node * 2].first, tree[node * 2 + 1].first);
        tree[node].second = max(tree[node * 2].second, tree[node * 2 + 1].second);
    }
}
pair<int,int> query(int node, int l, int r, int s, int e) {
    if(l > e || r < s) return make_pair(-1, -1);
    if(s <= l && r <= e) return tree[node];

    int m = (l + r) / 2;
    pair<int,int> t1 = query(node * 2, l, m, s, e);
    pair<int,int> t2 = query(node * 2 + 1, m + 1, r, s, e);
    if(t1.first == -1) {
        return t2;
    } else if(t2.first == -1) {
        return t1;
    } else {
        return make_pair(min(t1.first, t2.first), max(t1.second, t2.second));
    }
}
int main() {
    fastio;
    cin >> n >> m;
    a.resize(n + 1);
    int h = (int)ceil(log2(n));
    tree.resize(1 << (h + 1));
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    init(1,1,n);
    
    while(m--) {
        int a, b;
        cin >> a >> b;
        auto ans = query(1,1,n,a,b); 
        cout << ans.first << ' ' << ans.second << '\n';
    }
    return 0;
}