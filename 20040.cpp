#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
int p[500000];
int find(int x) {
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}
void set_union(int x, int y) {
    x = find(x);
    y = find(y);
    if(x != y) p[x] = y;
}
int main() {
    fastio;
    cin >> n >> m;

    memset(p,-1,sizeof(p));
    int idx = -1;
    for(int i = 1; i <= m; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        t1 = find(t1);
        t2 = find(t2);
        if(t1 == t2 && idx == -1) {
            idx = i;
        } else {
            set_union(t1, t2);
        }
    }

    cout << (idx == -1 ? 0 : idx) << '\n';

    return 0;
}