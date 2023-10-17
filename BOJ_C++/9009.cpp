#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int f[1000];
void solve() {
    int n; cin >> n;
    stack<int> st;
    int idx = -1;
    for(int i = 0; ; i++) {
        if(f[i] > n) {
            idx = i - 1;
            break;
        }
    }

    for(int i = idx; i >= 1; i--) {
        if(n == 0) break;
        if(n >= f[i]) {
            n -= f[i];
            st.push(f[i]);
        }
    }

    while((int)st.size()) {
        cout << st.top() << ' ';
        st.pop();
    }
    cout << '\n';
}

int main() {
    f[0] = 0; f[1] = 1;
    for(int i = 2; ;i++) {
        f[i] = f[i - 1] + f[i - 2];
        if(f[i] > 1000000000) break;
    }

    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }

    return 0;
}