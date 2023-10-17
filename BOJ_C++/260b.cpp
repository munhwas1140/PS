#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
int n, x, y, z;
vector<int> m[101], e[101], s[202];
bool check[1001];
int main() {
    fastio;
    cin >> n >> x >> y >> z;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        m[a[i]].push_back(i);
    }
    for(int i = 1; i <= n; i++) {
        int tmp; cin >> tmp;
        e[tmp].push_back(i);
        s[tmp + a[i]].push_back(i);
    }

    for(int i = 100; i >= 0; i--) {
        if(x == 0) break;
        for(int j = 0; j < m[i].size(); j++) {
            if(x == 0) break;
            if(!check[m[i][j]]) {
                check[m[i][j]] = true;
                x--;
            }
        }
    }

    for(int i = 100; i >= 0; i--) {
        if(y == 0) break;
        for(int j = 0; j < e[i].size(); j++) {
            if(y == 0) break;
            if(!check[e[i][j]]) {
                check[e[i][j]] = true;
                y--;
            }
        }
    }

    for(int i = 200; i >= 0; i--) {
        if(z == 0) break;
        for(int j = 0; j < s[i].size(); j++) {
            if(z == 0) break;
            if(!check[s[i][j]]) {
                check[s[i][j]] = true;
                z--;
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        if(check[i]) cout << i << '\n';
    }
    return 0;
}