#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
// 1 2 3 4 5 6 7 8 9 0
// 2 5 5 4 5 6 3 7 6 6
void solve() {
    int n; cin >> n;
    
    int tmp = n;
    int cnt = 0;
    while(tmp >= 14) {
        tmp -= 7;
        cnt++;
    }

    string s[14] = {"", "", "1", "7", "4", "2", "6", "8",
    "10", "18", "23", "20", "28", "68"};
    cout << s[tmp];
    for(int i = 0; i < cnt; i++) {
        cout << 8;
    }
    cout << ' ';


    tmp = n;
    if(tmp % 2 == 1) {
        cout << 7;
        tmp -= 3;
    } 
    for(int i = 0; i < tmp / 2; i++) {
        cout << 1;
    }
    cout << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}