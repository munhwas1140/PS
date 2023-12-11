#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
int p[300001];
bool check[300001];
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
int n, m;

int main() {
    fastio;
    memset(p,-1,sizeof(p));
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int t1, t2;
        cin >> t1 >> t2;
        if(!check[t1]) {
            check[t1] = true;
            set_union(t1, t2);
            cout << "LADICA" << '\n';
        } else if(!check[t2]) {
            check[t2] = true;
            set_union(t2, t1);
            cout << "LADICA" << '\n';
        } else {
            int x = find(t1);
            if(!check[x]) {
                set_union(x, t2);
                check[x] = true;
                cout << "LADICA" << '\n';
                continue;
            }
            x = find(t2);
            if(!check[x]) {
                set_union(x, t1);
                check[x] = true;
                cout << "LADICA" << '\n';
                continue;
            }
            
            cout << "SMECE" << '\n';
        }
    }
      
    return 0;
}