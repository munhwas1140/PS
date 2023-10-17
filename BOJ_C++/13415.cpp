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
    int k; cin >> k;

    int px, py, x, y;
    px = py = -1;
    int mv = -1;

    for(int i = 0; i < k; i++) {
        cin >> x >> y;
        mv = max({mv, x, y});
        if(y >= x) {

        } else {

        }
    }
    
    

    return 0;
}