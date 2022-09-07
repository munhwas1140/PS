#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
int n, k;
vector<pair<int,int>> tree;
int pos[100000];
void init(int node, int s, int e) {
    if(s == e) {
        tree[node] = make_pair(s, s);
    } else {
        int m = (s + e) / 2;
        init(node * 2, s, m);
        init(node * 2 + 1, m + 1, e);
        tree[node].first = max(tree[node * 2].first, tree[node * 2 + 1].first);
        tree[node].second = min(tree[node * 2].second, tree[node * 2 + 1].second); 
    }
}
void update(int node, int s, int e, int idx, int to) {
    if(idx < s || e < idx) return;
    if(s == e) {
        tree[node] = make_pair(to, to);
    } else {
        int m = (s + e) / 2;
        update(node * 2, s, m, idx, to);
        update(node * 2 + 1, m + 1, e, idx, to);
        tree[node].first = max(tree[node * 2].first, tree[node * 2 + 1].first);
        tree[node].second = min(tree[node * 2].second, tree[node * 2 + 1].second);
    }
}
pair<int,int> query(int node, int s, int e, int l, int r) {
    if(e < l || s > r) return make_pair(-1e9,1e9);
    if(l <= s && e <= r) return tree[node];
    
    int m = (s + e) / 2;
    auto t1 = query(node * 2, s, m, l, r);
    auto t2 = query(node * 2 + 1, m + 1, e, l, r);
    return make_pair(max(t1.first, t2.first), min(t1.second, t2.second)); 
}
int main() {
    fastio;
    int tc;
    cin >> tc;
    while(tc--) {
        cin >> n >> k;

        for(int i = 0; i < n; i++) {
            pos[i] = i;
        }

        tree.clear();
        int h = (int)ceil(log2(n));
        tree.resize(1 << (h + 1));
        init(1,0,n-1);

        while(k--) {
            int op, t1, t2;
            cin >> op >> t1 >> t2;
            if(op) {
                //check
                auto tmp = query(1,0,n-1,t1,t2);
                if(tmp.first == t2 && tmp.second == t1) {
                    cout << "YES" << '\n';
                } else cout << "NO" << '\n';
            } else {
                //update
                int x = pos[t1];
                int y = pos[t2];
                update(1,0,n-1,x,t2);
                update(1,0,n-1,y,t1);
                pos[t1] = y;
                pos[t2] = x;
            }
        } 
    }
      
    return 0;
}