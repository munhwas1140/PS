#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int Ctoi(char c) {
    if(c == 'A') return 1;
    else if(c == 'B') return 10;
    else if(c == 'C') return 100;
    else if(c == 'D') return 1000;
    return 10000;

}
void solve() {
    string str;
    cin >> str;
    int n = str.size();
    if(n == 1) {
        cout << 10000 << '\n';
        return ;
    }
    vector<vector<int>> cnt(5, vector<int>(n));
    vector<char> t = {'A', 'B', 'C', 'D','E'};
    vector<vector<int>> pos(5);
    vector<vector<int>> rpos(5);
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < n; j++) {
            if(j == 0) cnt[i][j] = (str[j] == t[i]);
            else cnt[i][j] = cnt[i][j - 1] + (str[j] == t[i]);
            if(str[j] == t[i]) {
                pos[i].push_back(j);
                rpos[i].push_back(-j);
            }
        }
        sort(rpos[i].begin(), rpos[i].end());
    }

    vector<int> psum(n);
    int mx = -1;
    for(int i = n - 1; i >= 0; i--) {
        char ch = str[i];
        int now = Ctoi(ch);
        if(now < mx) now *= -1;
        if(i == n - 1) psum[i] = now;
        else psum[i] = psum[i + 1] + now;
        mx = max(mx, abs(now));
    }

    vector<int> sum(n);
    for(int i = 0; i < n; i++) {
        char ch = str[i];
        int now = Ctoi(ch);
        if(i == 0) sum[i] = now;
        else sum[i] = sum[i - 1] + now;
    }

    vector<int> s = {1,10,100,1000,10000};
    int ans = psum[0];
    for(int i = 0; i < 5; i++) {
        bool ok = true;
        for(int j = i + 1; j < 5; j++) {
            if(lower_bound(pos[j].begin(), pos[j].end(), 1) != pos[j].end()) ok = false;
        }
        if(ok) ans = max(ans, psum[1] + s[i]);

        for(int j = 1; j < n; j++) {
            int tmp =  (j == n - 1 ? 0 : psum[j + 1]);
            for(int k = 0; k < i; k++) tmp -= cnt[k][j - 1] * s[k];

            for(int k = i; k < 5; k++) {
                int mx = -1;
                for(int x = k + 1; x < 5; x++) {
                    auto it1 = lower_bound(pos[x].begin(), pos[x].end(), j + 1);
                    if(it1 != pos[x].end()) mx = max(mx, *it1);
                    auto it2 = lower_bound(rpos[x].begin(), rpos[x].end(), -(j - 1));
                    if(it2 != rpos[x].end()) mx = max(mx, -(*it2));
                }
                if(mx == -1) {
                    tmp += cnt[k][j - 1] * s[k];
                    if(i == k) tmp += s[k];
                } else if(mx > j) {
                    tmp -= cnt[k][j - 1] * s[k];
                    if(i == k) tmp -= s[k];
                } else {
                    tmp += (cnt[k][j - 1] - cnt[k][mx]) * s[k];
                    if(i == k) tmp += s[k];
                    tmp -= (cnt[k][mx]) * s[k];
                }
            }
            ans = max(ans, tmp);
        }
    }
    cout << ans << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}