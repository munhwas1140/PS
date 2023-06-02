#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        string tmp; cin >> tmp;
        for(char &x : tmp) {
            a[i] |= 1 << (x - 'a');
        }
    }

    int now = (1 << 26) - 1;
    
    while(m--) {
        int op; char c;
        cin >> op >> c;
        now ^= (1 << (c - 'a'));
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] == (a[i] & now)) cnt++;
        }
        cout << cnt << '\n';
    }
    return 0;
}