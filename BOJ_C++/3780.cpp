#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

const int mod = 1000;
int n;

int p[20001];
int dist[20001];
int find(int x) {
    if(p[x] < 0) return x;
    int tmp = find(p[x]);
    dist[x] += dist[p[x]];
    p[x] = tmp;
    return tmp;
}
void set_union(int x, int y) {
    dist[x] = abs(x - y) % mod;
    p[x] = y;
}
int main() {
    fastio;
    int tc;
    cin >> tc;
    while(tc--) {
        memset(p,-1,sizeof(p));
        memset(dist,0,sizeof(dist));
        cin >> n;
        char op;
        while(true) {
            cin >> op;
            if(op == 'E') {
                int t1;
                cin >> t1; find(t1);
                cout << dist[t1] << '\n';
            } else if(op == 'I') {
                int t1, t2;
                cin >> t1 >> t2;
                set_union(t1, t2);
            } else {
                break;
            }
        }
    }
      
    return 0;
}