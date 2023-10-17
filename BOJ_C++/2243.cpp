#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

const int MAX = 1000000;
vector<int> tree;
int n;
void update(int node, int s, int e, int idx, int val) {
    if(idx < s || e < idx) return;
    if(s == e) {
        tree[node] += val;
    } else {
        int m = (s + e) / 2;
        update(node * 2, s, m, idx, val);
        update(node * 2 + 1, m + 1, e, idx, val);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
}
int find(int node, int s, int e, int tmp) {
    if(s == e) {
        tree[node] -= 1;
        return s;
    }
    int t1 = tree[node * 2];
    int t2 = tree[node * 2 + 1];
    int m = (s + e) / 2;
    int ans;
    if(tmp <= t1) {
        ans = find(node * 2, s, m, tmp);
    } else if(t1 < tmp) {
        ans = find(node * 2 + 1, m + 1, e, tmp - t1);
    }
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
    return ans;
}
int main() {
    fastio;
    cin >> n;
    int h = (int)ceil(log2(MAX + 1));
    tree.resize(1 << (h + 1));
    while(n--) {
        int op; cin >> op;
        if(op == 1) {
            int tmp; cin >> tmp;
            cout << find(1,1,MAX,tmp) << '\n';
        } else {
            int t1, t2;
            cin >> t1 >> t2;
            update(1,1,MAX,t1,t2);
        }
    }
    return 0;
}