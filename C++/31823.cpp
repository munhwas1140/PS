#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n, m; cin >> n >> m;
    vector<pair<int,string>> ans;
    set<int> st;

    for(int i = 0; i < n; i++) {
        int mx = 0;
        int now = 0;
        for(int j = 0; j < m; j++) {
            char c; cin >> c;
            if(c == '.') now++;
            else now = 0;
            mx = max(mx, now);
        }
        string str; cin >> str;
        ans.push_back({mx, str});
        st.insert(mx);
    }

    cout << st.size() << '\n';
    for(int i = 0; i < n; i++) {
        cout << ans[i].first << ' ' << ans[i].second << '\n';
    }

    return 0;
}
