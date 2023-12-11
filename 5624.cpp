#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
bool check[400004];
int main() {
    fastio;
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int ans = 0;
    for(int i = 0; i < n; i++) {

        for(int j = i - 1; j >= 0; j--) {
            check[a[j] + a[i - 1] + 200000] = true;
        }

        for(int j = i - 1; j >= 0; j--) {
            if(check[a[i] - a[j] + 200000]) {
                ans++;
                break;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}