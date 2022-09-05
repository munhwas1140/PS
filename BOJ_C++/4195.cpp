#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
int p[200000];
int find(int x) {
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}
int set_union(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return p[x];
    p[y] += p[x];
    p[x] = y;
    return p[y];
}
int main() {
    fastio;
    int tc;
    cin >> tc;
    while(tc--) {
        memset(p,-1,sizeof(p));
        int n;
        cin >> n;
        map<string, int> M;
        int cnt = 0; 
        for(int i = 0; i < n; i++) {
            string t1, t2;
            int x1, x2;
            cin >> t1 >> t2;
            if(M.count(t1) == 0) M[t1] = cnt++;
            if(M.count(t2) == 0) M[t2] = cnt++;
            x1 = M[t1]; x2 = M[t2];
            cout << -set_union(x1, x2) << '\n';
        }
    }
    return 0;
}