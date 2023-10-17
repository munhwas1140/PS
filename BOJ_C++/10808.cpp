#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int cnt[26] = {0};
    string str; cin >> str;
    for(auto &x : str) {
        cnt[x - 'a']++;
    }
    
    for(int i = 0; i < 26; i++) {
        cout << cnt[i] << ' ';
    }

    return 0;
}