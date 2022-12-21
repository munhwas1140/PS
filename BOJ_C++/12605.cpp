#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int main() {
    fastio;
    int tc; cin >> tc;
    cin.ignore();
    for(int TC = 1; TC <= tc; TC++) {
        string str, tmp, ans = "";
        getline(cin, str);
        istringstream in(str);
        while(in >> tmp) {
            ans = tmp + " " + ans;
        }
        cout << "Case #" << TC << ": " << ans << '\n';
    }
    return 0;
}