#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n;
    string str;

    cin >> n >> str;

    int cnt = 0;
    int rem = 0;
    for (int i = n - 1; i > 0; i--) {
        str[i] += rem;

        if (str[i] == '1') {
            cnt += 1;
            rem = 1;
        } else if (str[i] == '0') {
            rem = 0;
        }
    }
    cout << cnt << '\n';

    return 0;
}
