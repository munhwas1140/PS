#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;


int main() {
    fastio;
    int tc;
    cin >> tc;
    while(tc--) {
        int n; cin >> n;
        vector<int> psum(n + 1);
        for(int i = 0, tmp; i < n; i++) {
            cin >> tmp;
            psum[i + 1] = psum[i] + tmp; 
        }
    
        int ans = -1e9;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                ans = max(ans, psum[j+1] - psum[i]);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}