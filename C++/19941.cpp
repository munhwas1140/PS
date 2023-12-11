#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;
    
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(str[i] == 'P') {
            for(int j = -k; j <= k; j++) {
                if(i + j < 0 || i + j >= n) continue;
                if(str[i + j] == 'H') {
                    ans++;
                    str[i + j] = 'X';
                    break;
                }
            }
        }
    }
    
    cout << ans << '\n';

    return 0;
}