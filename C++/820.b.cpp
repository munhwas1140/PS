#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;

int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        int n; string str;
        cin >> n >> str;
        string ans = "";
        for(int i = n - 1; i >= 0; i--) {
            if(str[i] == '0') {
                ans = char((str[i - 2] - '0') * 10 + str[i - 1] - '0' - 1 + 'a') + ans;
                i -= 2;
            } else {
                ans = char(str[i] - '0' - 1 + 'a') + ans;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}