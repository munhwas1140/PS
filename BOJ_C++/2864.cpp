#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    string t1, t2;
    cin >> t1 >> t2;
    for(char &c : t1) {
        if(c == '6') c = '5';
    }
    for(char &c : t2) {
        if(c == '6') c = '5';
    }
    cout << stoi(t1) + stoi(t2) << ' ';

    for(char &c : t1) {
        if(c == '5') c = '6';
    }
    for(char &c : t2) {
        if(c == '5') c = '6';
    }

    cout << stoi(t1) + stoi(t2) << '\n';

    return 0;
}