#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int p[100001];
int op[100001];
int find(int x) {
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

void set_union(int x, int y) {
    x = find(x);
    y = find(y);
    if(x != y) {
        p[x] = y;
    }
}
int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    memset(p,-1,sizeof(p));
    bool ok = true;
    for(int i = 0; i < m; i++) {
        char t;
        int a, b;
        cin >> t >> a >> b;
        a = find(a); b = find(b);
        if(t == 'S') {
            if(op[a] == b || op[b] == a) ok = false;
            set_union(a, b);
            if(op[a] != 0 && op[b] != 0) {
                set_union(op[a], op[b]);
            }
        } else {
            if(a == b) ok = false;
            if(op[a] != 0) set_union(b, op[a]);
            if(op[b] != 0) set_union(a, op[b]);
            op[a] = b;
            op[b] = a;
        }
    }

    if(!ok) {
        cout << 0 << '\n';
        return 0;
    }

    for(int i = 1; i <= n; i++) {
        if(op[i] != 0) set_union(i, op[i]);
    }

    vector<bool> check(n + 1);
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        int x = find(i);
        if(check[x] == false) cnt++;
        check[x] = true;
    }
    cout << 1;
    for(int i = 0; i < cnt; i++) {
        cout << 0;
    }
    cout << '\n';
    return 0;
}