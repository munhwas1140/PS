#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
int p[1000001];
int n, m;
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
    while(m--) {
        int op, t1, t2;
        cin >> op >> t1 >> t2;
        if(!op) {
            set_union(t1, t2);
        } else {
            t1 = find(t1);
            t2 = find(t2);
            cout << (t1 == t2 ? "YES" : "NO") << '\n';
        }
    } 
      
    return 0;
}