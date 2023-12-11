#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n; string str; 
    cin >> n >> str;
    stack<char> st;
    int cnt = 0;
    int it = 0;
    while(it < n) {
        if(str[it] == '(') {
            if(it + 1 == n) {
                break;
            }
            cnt++;
            it += 2;
        } else {
            if(it + 1 == n) {
                break;
            } 
            if(str[it + 1] == ')') {
                cnt++;
                it += 2;
            } else {
                int e = it + 1;
                while(e < n && str[e] == '(') e++;
                if(e == n) break;
                cnt++;
                it = e + 1;
            }
        }
    }

    cout << cnt << ' ' << n - it << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}