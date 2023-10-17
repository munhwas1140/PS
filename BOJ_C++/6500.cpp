#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    while(1) {
        int n; cin >> n;
        if(n == 0) break;

        set<int> st;
        while(1) {
            if(st.count(n)) break;
            st.insert(n);
            n = (n * n) / 100 % 10000;
            // cout << n << '\n';
        }
        cout << (int)st.size() << '\n';
    }
    return 0;
}