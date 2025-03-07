#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

ll go(ll x, string str) {
    ll ret = 0;
    ll mul = 1LL;

    for (int i = (int)str.size() - 1; i >= 0; i--) {
        ll cnt;
        if ('0' <= str[i] && str[i] <= '9') {
            cnt = str[i] - '0';
        } else {
            cnt = str[i] - 'a' + 10;
        }
        if (cnt >= x) {
            return -1;
        }

        ret += cnt * mul;
        mul *= x;
    }
    return ret;
}

int main() {
    fastio;
    string a, b;
    cin >> a >> b;

    vector<tuple<ll, int, int>> ans;

    for (int i = 2; i <= 36; i++) {
        for (int j = 2; j <= 36; j++) {
            if (i == j) continue;
            ll ret1 = go(i, a);
            ll ret2 = go(j, b);

            if (ret1 == ret2 && ret1 != -1) {
                ans.emplace_back(ret1, i, j);
            }
        }
    }

    if (ans.size() == 0) {
        cout << "Impossible" << '\n';
    } else if (ans.size() == 1) {
        auto [val, t1, t2] = ans[0];
        cout << val << ' ' << t1 << ' ' << t2 << '\n';
    } else {
        cout << "Multiple" << '\n';
    }

    return 0;
}