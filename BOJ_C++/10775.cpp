#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
int n, m;
int p[100001];
bool check[100001];
int find(int x) {
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}
void set_union(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return ;
    p[x] = y;
}
int main() {
    fastio;
    memset(p,-1,sizeof(p));        
    cin >> n >> m;
    int ans = 0;
    while(m--) {
        int tmp; cin >> tmp;
        int x = find(tmp);
        if(x < 1) break;
        if(!check[x]) {
            check[x] = true;
            set_union(x, x - 1);
            ans += 1;
        }
    }      
    cout << ans << '\n';
    return 0;
}