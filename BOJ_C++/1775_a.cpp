#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    string str; cin >> str;
    int n = str.size();
    // if(n == 3) {
    //     cout << str[0] << ' ' << str[1] << ' ' << str[2] << '\n';
    // } else if((str.front() == 'a' && str.back() == 'a') || (str.front() == 'b' && str.back() == 'b')) {
    //     cout << str.front() << ' ' << string(str.begin() + 1, str.end() - 1) << ' ' << str.back() << '\n';
    // } else if(str.front() == 'a' && str.back() == 'b') {
    //     int it = 0;
    //     while(it < n && str[it] == 'a') it++;
    //     if(it != n - 1) {
    //         cout << string(str.begin(), str.begin() + it) << ' ';
    //         cout << string(str.begin() + it, str.end() - 1) << ' ';
    //         cout << str.back() << '\n';
    //     } else {
    //         cout << string(str.begin(), str.end() - 3) << 'z';
    //         cout << string(str.end() - 3, str.end() - 2) << ' ';
    //         cout << string(str.end() - 2, str.end()) << '\n';
    //     }
    // } else if(str.front() == 'b' && str.back() == 'a') {
    //     int it = 0;
    //     while(it < n && str[it] == 'b') it++;
    //     if(it != n - 1) {
    //         cout << string(str.begin(), str.begin() + it) << ' ';
    //         cout << string(str.begin() + it, str.begin() + it + 1) << ' ';
    //         cout << string(str.begin() + it + 1, str.end()) << '\n';
    //     } else {
    //         cout << string(str.begin(), str.begin() + 1) << ' ';
    //         cout << string(str.begin() + 1, str.end() - 1) << ' ';
    //         cout << string(str.end() - 1, str.end()) << '\n';
    //     }
    // } 

    int it = 0;
    for(int i = 1; i < n - 1; i++) {
        if(str[i] == 'a') {
            it = i;
            break;
        }
    }

    if(it) {
        cout << string(str.begin(), str.begin() + it) << ' ';
        cout << str[it] << ' ';
        cout << string(str.begin() + it + 1, str.end()) << '\n';
    } else {
        cout << str.front() << ' ';
        cout << string(str.begin() + 1, str.end() - 1) << ' ';
        cout << str.back() << '\n';
    }
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}