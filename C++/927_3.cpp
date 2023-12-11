#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
bool flag = true;
int f(string &str) {
    if(str == "HOURGLASS") flag ^= 1;
    return flag;
}
int now = 1;
int next() {
    if(flag) {
        if(now == 12) now = 1;
        else now += 1;
    } else {
        if(now == 1) now = 12;
        else now -= 1;
    }
    return now;
}
int main() {
    fastio;
    int n; cin >> n;

    for(int i = 0; i < n; i++) {
        string str; int t;
        cin >> str >> t;
        if(str == "HOURGLASS" && now == t) {
            cout << now << ' ' << "NO" << '\n';
            next();
        } else { 
            f(str);
            cout << now << ' ' << (now == t ? "YES" : "NO") << '\n';
            next();
        }
    }
    return 0;
}