#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int main() {
    fastio;
    string str; cin >> str;
    int s = 0;
    int e = str.size() - 1;
    while(s < e) {
        if(str[s] != str[e]) {
            return !(cout << (int)str.size() << '\n');
        }
        s++;
        e--;
    }
    s = 0;
    e = str.size() - 2;
    while(s < e) {
        if(str[s] != str[e]) {
            return !(cout << (int)str.size() - 1 << '\n');
        }
        s++;
        e--;
    }
    cout << -1 << '\n';
    return 0;
}