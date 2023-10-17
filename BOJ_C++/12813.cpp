#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    string a, b;
    cin >> a >> b;
    int sz = a.size();
    int u, v;
    for(int i = 0; i < sz; i++) {
        u = a[i] - '0';
        v = b[i] - '0';
        cout << (u & v);
    }
    cout << '\n';

    for(int i = 0; i < sz; i++) {
        u = a[i] - '0';
        v = b[i] - '0';
        cout << (u | v);
    }
    cout << '\n';

    for(int i = 0; i < sz; i++) {
        u = a[i] - '0';
        v = b[i] - '0';
        cout << (u ^ v);
    }
    cout << '\n';

    for(int i = 0; i < sz; i++) {
        u = a[i] - '0';
        cout << (!u);
    }
    cout << '\n';

    for(int i = 0; i < sz; i++) {
        u = b[i] - '0';
        cout << (!u);
    }
    cout << '\n';


    return 0;
}