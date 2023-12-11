#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n; cin >> n;
    int now = 0;
    int it = 0;
    deque<int> a;
    bool f = false;
    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        if(a.size() == 0) {
            a.push_back(tmp);
            cout << 1;
        } else {
            if(tmp >= a.back()) {
                if(f) {
                    if(tmp > a.front()) cout << 0;
                    else {
                        a.push_back(tmp);
                        cout << 1;
                    }

                } else {
                    a.push_back(tmp); cout << 1;
                }
            } else {
                if(f  == false && tmp <= a.front()) {
                    f = true;
                    a.push_back(tmp);
                    cout << 1;
                } else {
                    cout << 0;
                }
            }
        }
    }
    cout << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}