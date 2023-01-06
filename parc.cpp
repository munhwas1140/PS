#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n; cin >> n;
    int cnt[200001] = {0};
    bool ok = true;
    int mx = -1;
    vector<pii> a(n);
    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        a[i] = {tmp, i};
        mx = max(tmp, mx);
        cnt[tmp]++;
        if(cnt[tmp] > 3) {
            ok = false;
        }
    }

    if(mx != n || !ok) {
        cout << "NO" << '\n';
        return ;
    }

    sort(a.begin(), a.end());
    vector<vector<int>> ans(2, vector<int>(n));
    vector<vector<bool>> check(2, vector<bool>(n + 1));

    int uit = 1;
    int dit = 1;

    for(auto &[val, idx] : a) {
        if(cnt[val] == 2) {
            if(check[1][val]) {
                cout << "NO" << '\n';
                return ;
            }
            check[1][val] = true;
            ans[1][idx] = val;
            while(check[0][uit]) uit++;
            check[0][uit] = true;
            if(uit > val) {
                cout << "NO" << '\n';
                return ;
            }
            ans[0][idx] = uit++;
            cnt[val]--;
        } else {
            if(check[0][val]) {
                cout << "NO" << '\n';
                return ;
            }
            check[0][val] = true;
            ans[0][idx] = val;
            while(check[1][dit]) dit++;
            check[1][dit] = true;
            if(val < dit) {
                cout << "NO" << '\n';
                return ;
            }
            ans[1][idx] = dit++;
            cnt[val]--;
        }
    }

    cout << "YES" << '\n';
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < n; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
    return ;
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}