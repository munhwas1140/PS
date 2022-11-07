#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n; cin >> n;
    string str; cin >> str;

    int it = 0;
    while(it < n && str[it] == '?') it++;
    if(it == n) {
        for(int i = 0; i < n; i++) str[i] = (i % 2 ? 'B' : 'R');
    } else {
        for(int i = it - 1; i >= 0; i--) {
            if(it % 2 == i % 2) {
                str[i] = str[it];
            } else {
                str[i] = (str[it] == 'B' ? 'R' : 'B');
            }
        }
    }

    for(int i = it; i < n; i++) {
        if(str[i] == '?') {
            int j = i;
            while(j < n && str[j] == '?') {
                j++;
            }
            
            char c = str[i - 1];
            for(int k = i; k < j; k++) {
                if(k % 2 == (i - 1) % 2) {
                    str[k] = c;
                } else {
                    str[k] = (c == 'B' ? 'R' : 'B');
                }
            }
            i = j - 1;
        }
    }

    cout << str << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}