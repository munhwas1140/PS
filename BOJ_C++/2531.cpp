#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
int check[3001];
int main() {
    fastio;
    int n, d, k, c;
    cin >> n >> d >> k >> c;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < k; i++) {
        a.push_back(a[i]);
    }

    check[c] = 1e9;
    int ans = 1;
    int now = 1;
    
    for(int i = 0; i < n + k; i++) {
        if(i >= k) {
            if(--check[a[i-k]] == 0) now -= 1;
        }
        if(++check[a[i]] == 1) now += 1;
        ans = max(ans, now);
    }

    cout << ans << '\n';
      
    return 0;
}