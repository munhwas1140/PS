#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = 998244353;
void solve() {
    int n; cin >> n;
    vector<vector<int>> a(n + 1, vector<int>(n + 1, 0));
    bool ok = true;
    for(int i = 1; i <= n; i++) {
        bool check = true;

        for(int j = i; j <= n; j++) {
            cin >> a[i][j];
            if(a[i][j] == 2) check = false;
            if(i == j && a[i][j] == 2) ok = false;
            if(!check && a[i][j] == 1) ok = false;
        }
    }

    if(!ok) {
        cout << 0 << '\n';
        return ;
    }


    vector<int> b(n + 1);
    for(int i = 1; i <= n; i++) {
        b[i] = i;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            if(a[i][j] == 1) {
                b[j] = min(b[j], i);
            }
        }
    }
    for(int i = n - 1; i >= 1; i--) {
        b[i] = min(b[i], b[i + 1]);
    }

    int sz = 0;
    map<int,int> mp;
    for(int i = 1; i <= n; i++) {
        int it = i;
        mp[b[i]] = sz++;
        while(it <= n && b[i] == b[it]) it++;
        i = it - 1;
    }
    cout << sz << '\n';
    vector<vector<bool>> check(sz, vector<bool>(sz, false));

    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            if(a[i][j] == 2) {
                check[mp[b[i]]][mp[b[j]]] = true;
            }
        }
    }
}
int main() {
    fastio;
    solve();
    return 0;
}