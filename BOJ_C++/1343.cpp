#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    string str;
    cin >> str;
    int n = str.size();

    for(int i = 0; i < n; i++) {
        if(str[i] == '.') continue;
        int it = 0;
        while(i + it < n && it < 4 && str[i + it] == 'X') it++;
        if(it == 4) {
            for(int j = 0; j < 4; j++) {
                str[i + j] = 'A';
            }
        } else if(it == 2) {
            for(int j = 0; j < 2; j++) {
                str[i + j] = 'B';
            }
        } else {
            cout << -1 << '\n';
            return 0;
        }
        i += it - 1;
    }
    cout << str << '\n';

    return 0;
}