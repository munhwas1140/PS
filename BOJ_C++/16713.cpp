#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    vector<int> psum(n+1);
    for(int i = 0, tmp; i < n; i++) {
        cin >> tmp;
        psum[i+1] = psum[i] ^ tmp;
    } 
    int ans = 0; 
    while(m--) {
        int t1, t2;
        cin >> t1 >> t2;
        ans ^= psum[t2] ^ psum[t1-1]; 
    }
    cout << ans << '\n';
    return 0;
}