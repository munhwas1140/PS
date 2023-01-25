#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> pos(n, vector<int>(10));
    vector<int> ans(n + 1);
    set<string> st;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
            a[i][j]--;
            pos[i][a[i][j]] = j;
        }
        string tmpstr = "";
        for(int j = 0; j < m; j++) {
            tmpstr.push_back(char(pos[i][j] + '0'));
            st.insert(tmpstr);
        }
    }

    for(int i = 0; i < n; i++) {
        string now = "";
        for(int j = 0; j < m; j++) {
            now.push_back(char(a[i][j] + '0'));
            if(st.count(now)) {
                ans[i] = j + 1;
            } else {
                break;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}