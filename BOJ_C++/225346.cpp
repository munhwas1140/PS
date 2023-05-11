#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n; cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    sort(a.begin(), a.end());
    
    if(a[0] == 0) {
        bool f = true;
        for(int i = 1; i < n; i++) {
            if(a[i] != 0) {
                f = false; break;
            }
        }

        if(f) cout << 1 << '\n';
        else {
            int it = 0;
            for(int i = 0; i < n; i++) {
                if(a[i] == it) it++;
                else if(a[i] > it) break;
            }
            cout << it + 2 << '\n';
        }
    } else {
        cout << 0 << '\n';
    }

    return 0;
}