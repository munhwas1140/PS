#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

int a[1000000];
int psum[1000001];
int mod[1001];
int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    ll ans = 0;
    mod[0] = 1;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] %= m;
        psum[i+1] = (psum[i] + a[i]) % m;
        ans += mod[psum[i+1]];
        mod[psum[i+1]] += 1;
    } 

    cout << ans << '\n';
    return 0;
}