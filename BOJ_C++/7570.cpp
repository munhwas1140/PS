#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n;
int order[1000001];
int tmp[1000001];
int main() {
    fastio;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int tmp; cin >> tmp;
        order[tmp] = i;
    }
    
    int ans = n;
    for(int i = 1; i < n; i++) {
        if(order[i + 1] > order[i]) {
            tmp[i + 1] = tmp[i] + 1;
            ans = min(ans, n - tmp[i + 1] - 1);
        }
    }
    cout << ans << '\n';


    return 0;
}