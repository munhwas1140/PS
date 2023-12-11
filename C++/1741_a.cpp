#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int to(char x) {
    if(x == 'L') return 3;
    else if(x == 'M') return 2;
    else return 1;
}
void solve() {
    string a, b;
    cin >> a >> b;
    int ta, tb;
    ta = to(a.back());
    tb = to(b.back());
    if(ta > tb){
        cout << ">" << '\n';
    } else if(ta < tb) {
        cout << "<" << '\n';
    } else {
        if(ta == 1) {
            if(a.size() > b.size()) {
                cout << '<' << '\n';
            } else if(a.size() < b.size()) {
                cout << '>' << '\n';
            } else cout << '=' << '\n';
        } else {
            if(a.size() > b.size()) {
                cout << '>' << '\n';
            } else if(a.size() < b.size()) {
                cout << '<' << '\n';
            } else cout << '=' << '\n';
        }
    }
    return ;
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }

    return 0;
}
