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
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    int it = 0;
    for(int i = 0; i < n; i++) {
        a[i] -= n - i - 1;
        if(a[i] > 0) {
            bool f = false;
            while(it < i) {
                while(true) {
                    if(a[it] == 0) break;
                    a[it]++;
                    a[i]--;
                    if(a[i] == 0) {
                        f = true;
                        break;
                    }
                }

                if(f) break;
                it++;
            }
            if(!f) return !(cout << -1 << '\n');
        }
    }

    for(int i = 0; i < n; i++) {
        if(a[i] < 0) return !(cout << -1 << '\n');
    }
    cout << 1 << '\n';
    return 0;
}