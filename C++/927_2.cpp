#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n; cin >> n;
    map<string, int> mp;
    for(int i = 0; i < n; i++) {
        string str;
        int tmp;
        cin >> str >> tmp;
        mp[str] += tmp;
    }
    for(auto it : mp) {
        if(it.second == 5) return !(cout << "YES" << '\n');
    }
    cout << "NO" << '\n';
    return 0;
}