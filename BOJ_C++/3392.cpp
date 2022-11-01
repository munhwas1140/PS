#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
vector<int> lazy, tree;
void update_lazy(int node, int s, int e) {
    if(lazy[node] != 0) {
        tree[node] += (e - s + 1) * lazy[node];
        if(s != e) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    return ;
}

void update(int node, int s, int e, int l, int r, long long v) {
    update_lazy(node,s,e);
    if(e < l || s > r) return ;
    if(l <= s && e <= r) {
        tree[node] += (e - s + 1) * v;
        if(s != e) {
            lazy[node*2] += v;
            lazy[node*2+1] += v;
        }
        return ;
    }
    int m = (s + e) >> 1;
    update(node*2, s, m, l, r, v);
    update(node*2+1, m+1, e, l, r, v);
    tree[node] = tree[node*2] + tree[node*2+1];
    return ;
}
long long query(int node, int start,int end,int i,int j) {
    update_lazy(node,start,end);
    if(i>end || j<start) return 0;
    if(i<=start && end<=j) return tree[node];

    int mid = (start + end) / 2;
    long long m1 = query(node*2,start,mid,i,j);
    long long m2 = query(node*2+1,mid+1,end,i,j);
    return m1 + m2;
}
int main() {
    fastio;
    int n; cin >> n;
    int h = (int)ceil(log2(30001));
    tree.resize(1 << (h + 1));
    lazy.resize(1 << (h + 1));
    
    vector<tuple<int,int,int,int>> v(n * 2);
    for(int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        v[i * 2] = make_tuple(x1, y1, y2, 0);
        v[i * 2 + 1] = make_tuple(x2, y1, y2, 1);
    }
    sort(v.begin(), v.end());
    
    
    int pre = 0;
    int ans = 0;
    for(auto [now, y1, y2, flag] : v) {
        int tmp = query(1,0,30000,0,30000);
        ans += (now - pre) * tmp;
        if(flag) {
            update(1,0,30000,y1,y2,-1);
        } else {
            update(1,0,30000,y1,y2,1);
        }
    }
    cout << ans << '\n';



    return 0;
}