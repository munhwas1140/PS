#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
int n, m;
int p[201];
int find(int x) {
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}
void set_union(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return;
    p[x] = y;
}
int main() {
    fastio;
    memset(p,-1,sizeof(p));
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int tmp; cin >> tmp;
            if(tmp) {
                set_union(i + 1, j + 1);
            }
        }
    }
    vector<int> seq(m);
    for(int &x : seq) cin >> x;
    bool ok = true;
    for(int i = 0; i < m - 1; i++) {
        if(find(seq[i]) != find(seq[i+1])) {
            ok = false;
            break;
        }
    }
    if(ok) cout << "YES" << '\n';
    else cout << "NO" << '\n';
    return 0;
}