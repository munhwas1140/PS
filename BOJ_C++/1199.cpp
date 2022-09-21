#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
int a[1001][1002];
int nxt[1001];
int n;
void go(int now) {
    for(int &x = nxt[now]; x <= n; x++) {
        while(x <= n && a[now][x]) {
            a[now][x]--;
            a[x][now]--;
            go(x);
        }
    }
    cout << now << ' ';
}
int main() {
    fastio;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= n; i++) {
        int deg = 0;
        for(int j = 1; j <= n; j++) deg += a[i][j];
        if(deg % 2) return !(cout << -1 << '\n');
    }
    go(1);
    return 0;
}