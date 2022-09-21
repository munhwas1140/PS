#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
int k, m,km1;
int p = -1, pv[4200005];
int nex;
void dfs(int x) {
    while(pv[x] != k) {
        nex = x*k%km1+pv[x];
        pv[x]++;
        dfs(nex);
    }
    if(p != -1) cout << p << ' ';
    p = x % k;
}
int main() {
    fastio;
    cin >> k >> m;
    if(m == 1) {
        for(int i = 0; i < k; i++) {
            cout << i << ' ';
        }
    } else {
        km1 = pow(k, m - 1);
        dfs(0);
    }
    return 0;
}