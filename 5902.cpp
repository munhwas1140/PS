#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n, l;
    cin >> n >> l;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
        
    vector<int> diff(n - 1);
    for(int i = 0; i < n - 1; i++) {
        diff[i] = a[i + 1] - a[i];
    }

    function<bool(int, int)> check = [&] (int s, int e) {
        for(int i = 0; i < e - s; i++) {
            if(diff[s + i] != diff[e - i]) return false;
        }
        return true;
    };

    int ans = 0;
    for(int i = 0; i < n - 1; i++) {
        if(check(0,i)) ans++;
    }

    for(int i = 1; i < n - 1; i++) {
        if(check(i, n - 2)) ans++;
    }
    
    cout << ans << '\n';

    return 0;
}