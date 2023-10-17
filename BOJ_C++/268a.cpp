#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;

int main() {
    fastio;
    set<int> s;
    for(int i = 0; i < 5; i++) {
        int tmp; cin >> tmp;
        s.insert(tmp);
    }
    cout << s.size() << '\n';

    return 0;
}