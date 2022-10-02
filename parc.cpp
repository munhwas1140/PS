#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, k;
map<vector<int>, int> M;
vector<vector<int>> a;
int main() {
    fastio;
    cin >> n >> k;
    a.resize(n + 1);
    for(int i = 1; i <= n; i++) {
        a[i].resize(k);
        for(int j = 0; j < k; j++) {
            cin >> a[i][j];
        }
        M[a[i]] = i;
    }


    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        ll cnt = 0;
        for(int j = i + 1; j <= n; j++) {
            if(i == j) continue;
            vector<int> tmp(k);
            for(int x = 0; x < k; x++) {
                if(a[i][x] == a[j][x]) tmp[x] = a[i][x];
                else tmp[x] = 3 - a[i][x] - a[j][x];
            }
            
            if(M.count(tmp) && (M[tmp] > j || M[tmp] < i)) {
                cnt++;
            }
        }

        for(int j = 1; j < i; j++) {
            vector<int> tmp(k);
            for(int x = 0; x < k; x++) {
                if(a[i][x] == a[j][x]) tmp[x] = a[i][x];
                else tmp[x] = 3 - a[i][x] - a[j][x];
            }
            
            if(M.count(tmp) && M[tmp] < j) {
                cnt++;
            }
        }
        ans += (cnt * (cnt - 1)) / 2;
    }

    cout << ans << '\n';

    return 0;
}