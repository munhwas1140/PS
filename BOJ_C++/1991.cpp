#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
struct asdf {
    int l, r;
};

asdf g[26];

void pre(int now) {
    if(now == -1) return ;
    cout << char(now + 'A');
    pre(g[now].l);
    pre(g[now].r);
}

void ino(int now) {
    if(now == -1) return ;
    ino(g[now].l);
    cout << char(now + 'A');
    ino(g[now].r);
}

void post(int now) {
    if(now == -1) return ;
    post(g[now].l);
    post(g[now].r);
    cout << char(now + 'A');
}
int main() {
    fastio;
    int n;
    cin >> n;
      
    for(int i = 0; i < n; i++) {
        char x, y, z;
        cin >> x >> y >> z;
        x -= 'A';
        if(y == '.') g[x].l = -1;
        else g[x].l = y - 'A';
        
        if(z == '.') g[x].r = -1;
        else g[x].r = z - 'A';

    }

    pre(0);
    cout << '\n';
    ino(0);
    cout << '\n';
    post(0);
    return 0;
}