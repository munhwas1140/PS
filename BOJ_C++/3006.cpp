#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
int n;
vector<int> tree;
void init(int node, int s, int e) {
    if(s == e) tree[node] = 1;
    else {
        int m = (s + e) / 2;
        init(node * 2, s, m);
        init(node * 2 + 1, m + 1, e);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
}
int query(int node, int s, int e, int l, int r) {
    if(s > r || e < l) return 0;
    if(l <= s && e <= r) return tree[node];
    int m = (s + e) / 2;
    int t1 = query(node * 2, s, m, l, r);
    int t2 = query(node * 2 + 1, m + 1, e, l, r);
    return t1 + t2;
}
void update(int node, int s, int e, int idx) {
    if(s > idx || e < idx) return;
    if(s == e) tree[node] -= 1;
    else {
        int m = (s + e) / 2;
        update(node * 2, s, m, idx);
        update(node * 2 + 1, m + 1, e, idx);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
}
int main() {
    fastio;
    cin >> n;
    int h = (int)ceil(log2(n + 1));
    tree.resize(1 << (h + 1));
    init(1,1,n);
    vector<pair<int,int>> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].first; a[i].second = i + 1;
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < (n + 1) / 2; i++) {
        cout << query(1, 1, n, 1, a[i].second - 1) << '\n';
        update(1, 1, n, a[i].second);
        if(i >= n - i - 1) break;
        cout << query(1,1,n,a[n-i-1].second + 1, n) << '\n';
        update(1,1,n,a[n-i-1].second);
    }
      
    return 0;
}