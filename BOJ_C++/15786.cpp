#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    string str;
    cin >> str;

    for(int i = 0; i < m; i++) {
        string tmp; cin >> tmp;
        int it = 0;
        for(auto &c : tmp) {
            if(it == n) break;
            if(c == str[it]) it++;
        }

        if(it == n) cout << "true" << '\n';
        else cout << "false" << '\n';
    }

    return 0;
}