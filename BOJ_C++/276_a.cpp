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
    int it = -1;
    for(int i = 0; i < str.size(); i++) {
        if(str[i] == 'a') it = i + 1;
    }
    cout << it << '\n';

    return 0;
}