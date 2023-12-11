#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1), pXOR(n + 1);
    vector<ll> pSUM(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        pXOR[i] = pXOR[i - 1] ^ a[i];
        pSUM[i] = pSUM[i - 1] + a[i];
    }

    vector<int> las(n + 1);
    map<int,int> mp;
    for(int i = 1; i <= n; i += 2) {
        mp[pXOR[i - 1]] = i;
        if(mp.count(pXOR[i])) las[i] = mp[pXOR[i]];
    }

    mp.clear();
    for(int i = 2; i <= n; i += 2) {
        mp[pXOR[i - 1]] = i;
        if(mp.count(pXOR[i])) las[i] = mp[pXOR[i]];
    }
    
    for(int i = 1; i <= n; i++) {
        cout << las[i] << ' ';
    }
    cout << '\n';
    while(q--) {
        int l, r;
        cin >> l >> r;
        if(pXOR[r] ^ pXOR[l - 1]) {
            cout << -1 << '\n';
        } else if(pSUM[r] == pSUM[l - 1]) {
            cout << 0 << '\n';
        } else if((r - l + 1) % 2) {
            cout << 1 << '\n';
        } else {
            if(a[l] == 0 || a[r] == 0) cout << 1 << '\n';
            else if(las[r] >= l) cout << 2 << '\n';
            else cout << -1 << '\n';
        }
    }
}
int main() {
    fastio;
    solve();
    return 0;
}