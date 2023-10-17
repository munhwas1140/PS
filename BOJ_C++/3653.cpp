#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
const int MAX = 2e5 + 1;
int n, m;
vector<int> tree;
int pos[100001];
void init(int node, int s, int e) {
    if(s == e) {
        if(100001 <= s  && s < 100001 + n) tree[node] = 1;
        else tree[node] = 0;
    } else {
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
void update(int node, int s, int e, int idx, int val) {
    if(s > idx || e < idx) return;
    if(s == e) {
        tree[node] += val;
    } else {
        int m = (s + e) / 2;
        update(node * 2, s, m, idx, val);
        update(node * 2 + 1, m + 1, e, idx, val);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
}
int main() {
    fastio;
    int tc;
    cin >> tc;
    while(tc--) {
        memset(pos,-1,sizeof(pos));
        tree.clear();
        cin >> n >> m;
        int s = 1e5 + 1;
        int h = (int)ceil(log2(2e6 + 1));
        tree.resize(1 << (h + 1));
        for(int i = 1; i <= n; i++) {
            pos[i] = s + i - 1;
        }
        init(1,1,MAX);
        while(m--) {
            int tmp; cin >> tmp;
            cout << query(1, 1, 2e5 + 1, 1, pos[tmp] - 1) << ' ';
            update(1, 1, MAX, pos[tmp], -1);
            pos[tmp] = --s;
            update(1, 1, MAX, pos[tmp], 1);
        }
        cout << '\n';
    }     
      
    return 0;
}