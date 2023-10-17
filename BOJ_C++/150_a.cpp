#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        int n, k;
        cin >> n >> k;
        string str; cin >> str;
        int m = 0;
        for(int i = 0; i < n; i++) {
            if(str[i] == '1') m++;
        }
        if(m > k) {
            cout << "No" << '\n';
            continue;
        }
        int anscnt = 0;
        int zcnt = 0;
        int ocnt = 0;
        for(int i = 0; i < n; i++) {
            if(str[i] == '1') ocnt++;
            if(str[i] == '0') zcnt++;
            if(i - k >= 0 && str[i - k] == '1') ocnt--;
            if(i - k >= 0 && str[i - k] == '0') zcnt--;
            
            if(i >= k - 1 && ocnt == m && zcnt == 0) anscnt++;
        }
        if(anscnt == 1) {
            cout << "Yes" << '\n';
        } else {
            cout << "No" << '\n';
        }
    }
    return 0;
}