#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
int n, k, q;
int main() {
    fastio;
    cin >> n >> k >> q;
    vector<int> a(k + 1);
    for(int i = 1; i <= k; i++) {
        cin >> a[i];
    }

    while(q--) {
        int tmp; cin >> tmp;
        if(a[tmp] == n) continue;
        if(tmp < k) {
            if(a[tmp + 1] > a[tmp] + 1) {
                a[tmp]++;
            }
        } else {
            a[tmp]++;
        }
    }
    
    for(int i = 1; i <= k; i++) {
        cout << a[i] << ' ';
    }
    cout << '\n';

    return 0;
}