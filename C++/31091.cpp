#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n; cin >> n;
    vector<int> p(n + 1), m(n + 1);
    vector<int> psum(n + 1), msum(n + 1);
    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        if(tmp > 0) p[tmp]++;
        else m[-tmp]++;
    }

    msum[0] = m[0];
    for(int i = 1; i <= n; i++) {
        psum[i] = psum[i - 1] + p[i];
        msum[i] = msum[i - 1] + m[i];
    }

    vector<int> ans;
    for(int i = 0; i <= n; i++) {
        int tmp = 0;
        if(i != 0) tmp += msum[i - 1];
        if(tmp == i) ans.push_back(i);
    }

    cout << ans.size() << '\n';
    for(int x : ans) cout << x << ' ';
    cout << '\n';
}
int main() {
    fastio;
    solve();
    return 0;
}