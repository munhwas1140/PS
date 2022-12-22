#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
int p[10000], sz[10000], e[10000];
int find(int x ) {
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

int set_union(int x, int y) {
    if(x == -1 || y == -1) return max(x, y);
    x = find(x);
    y = find(y);
    if(x != y) {
        sz[y] += sz[x];
        p[x] = y;
    }
    return y;
}

bool ack(int x, int y) {
    x = find(x);
    y = find(y);

    if(e[x] == y) return false;
    
    int a = set_union(x, y), b = set_union(e[x], e[y]);
    e[a] = b;
    if(b != -1) e[b] = a; 
    return true;
}

bool dis(int x, int y) {
    x = find(x);
    y = find(y);

    if(x == y) return false;

    int a = set_union(x, e[y]), b = set_union(y, e[x]);
    e[a] = b;
    e[b] = a;
    return true;
}

void init() {
    memset(p,-1,sizeof(p));
    memset(e
    ,-1,sizeof(p));
    fill(sz, sz + 10000, 1);
}

void solve() {
    init();
    cin >> n >> m;

    int cont = -1;
    for(int i = 1; i <= m; i++) {
        string str;
        int x, y;
        cin >> str >> x >> y;
        if(str == "ACK") {
            if(!ack(x, y) && cont == -1) cont = i;
        } else {
            if(!dis(x, y) && cont == -1) cont = i;
        }
    }

    if(cont != -1) {
        cout << "CONTRADICTION AT " << cont << '\n';
    } else {

        int ret = 0;
        for(int i = 0; i < n; i++) {
            if(find(i) == i) {
                int ene = e[i];
                if(ene > i) continue;
                int mysz = sz[find(i)];
                int esz = e[find(i)] == -1 ? 0 : sz[e[find(i)]];
                ret += max(mysz, esz);
            }
        }
        cout << "MAX PARTY SIZE IS " << ret << '\n';
        // for(int i = 0; i < n; i++) {
        //     cout << find(i) << ' ';
        // }
        // cout << '\n';
        // for(int i = 0; i < n; i++) {
        //     cout << e[i] << ' ';
        // }


    }

}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}