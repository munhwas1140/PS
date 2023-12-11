#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
struct asdf {
    int x, y, z;
};

bool cmp(asdf a, asdf b) {
    return a.x < b.x;
}

int n;
asdf a[500001];
vector<int> tree;
void init(int node, int s, int e) {
    if(s == e) tree[node] = 1e9;
    else {
        int m = (s + e) / 2;
        init(node * 2, s, m);
        init(node * 2 + 1, m + 1, e);
        tree[node] = 1e9;
    }
}

void update(int node, int s, int e, int idx, int val) {
    if(s > idx || e < idx) return;
    if(s == e) {
        tree[node] = val;
        return ;
    }
    int m = (s + e) / 2;
    update(node * 2, s, m, idx, val);
    update(node * 2 + 1, m + 1, e, idx, val);
    tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}

int query(int node, int s, int e, int l, int r) {
    if(s > r || e < l) return 1e9;
    if(l <= s && e <= r) return tree[node];
    int m = (s + e) / 2;
    int t1 = query(node * 2, s, m, l, r);
    int t2 = query(node * 2 + 1, m + 1, e, l, r);
    return min(t1, t2);
}
int main() {
    fastio;
    cin >> n;
    int h = (int)ceil(log2(n));
    tree.resize(1 << (h + 1));
    for(int i = 1; i <= n; i++) {
        int t; cin >> t; a[t].x = i;
    } 
    for(int i = 1; i <= n; i++) {
        int t; cin >> t; a[t].y = i;
    } 
    for(int i = 1; i <= n; i++) {
        int t; cin >> t; a[t].z = i;
    } 
    sort(a + 1, a + n + 1, cmp);
    init(1,1,n);
    
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        // 세그먼트 트리에 값이 있다는것 -> 첫번째 시험을 잘 봤다는것
        // [1, a[i].y-1] 에 값이 있다는것 -> 두번째 시험을 잘 본 사람이 있다는것
        // 그 값이 a[i].z 보다 작다면 -> 세번째 시험을 더 잘 본 사람이 있다는것이므로 굉장한 학생이 아니게됨

        if(query(1,1,n,1,a[i].y - 1) > a[i].z) {
            ans++;
        }
        update(1,1,n,a[i].y, a[i].z);
    }
    cout << ans << '\n';
    return 0;
}