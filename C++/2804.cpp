#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    int ia, ib;
    auto tmp = [&] (void) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(a[i] == b[j]) {
                    ia = i;
                    ib = j;
                    return ;
                }
            }
        }
    };
    tmp();

    vector<string> ans(m, string(n,'.'));
    ans[ib] = a;
    for(int i = 0; i < m; i++) {
        ans[i][ia] = b[i];
    }
    for(int i = 0; i < m; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}