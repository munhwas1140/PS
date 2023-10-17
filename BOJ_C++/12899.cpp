#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MAX = 2000000;
vector<int> tree;
void update(int node, int s, int e, int idx) {
    if(idx < s || e < idx) return ;
    if(s == e) {
        tree[node]++;
    } else {
        int mid = (s + e) / 2;
        update(node * 2, s, mid, idx);
        update(node * 2 + 1, mid + 1, e, idx);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
}
int query(int node, int s, int e, int k) {
    if(s == e) {
        tree[node]--;
        return s;
    }

    int l = tree[node * 2];
    int r = tree[node * 2 + 1];
    int mid = (s + e) / 2;
    int ans;
    if(l < k) {
        ans = query(node * 2 + 1, mid + 1, e, k - l);
    } else {
        ans = query(node * 2, s, mid, k);
    }
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
    return ans;
}
int main() {
    fastio;

    int n; cin >> n;

    int h = ceil(log2(MAX + 1));
    tree.resize(1 << (h + 1));

    while(n--) {
        int op; cin >> op;
        if(op == 1) {
            int t; cin >> t;
            update(1, 1, MAX, t);
        } else if(op == 2) {
            int k; cin >> k;
            cout << query(1, 1, MAX, k) << '\n';
        }
    }

    return 0;
}