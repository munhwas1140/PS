#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;

int main() {
    fastio;
    bool check[1000001] = {false, };

    int n, w;
    cin >> n >> w;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for(int i = 0; i < n; i++) {
        if(a[i] <= w) check[a[i]] = true;
        for(int j = i + 1; j < n; j++) {
            if(a[i] + a[j] <= w) check[a[i] + a[j]] = true;
            for(int k = j + 1; k < n; k++) {
                if(a[i] + a[j] + a[k] <= w) check[a[i] + a[j] + a[k]] = true;
            }
        }
    }
    
    int ans = 0;
    for(int i = 1; i <= w; i++) {
        if(check[i]) ans++;
    }
    cout << ans << '\n';
    return 0;
}