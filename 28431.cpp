#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    set<int> st;
    for(int i = 0; i < 5; i++) {
        int tmp; cin >> tmp;
        if(st.count(tmp)) st.erase(tmp);
        else st.insert(tmp);
    }
    cout << *(st.begin()) << '\n';

    return 0;
}