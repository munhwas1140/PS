#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;

    set<int> st;
    st.insert(0);
    st.insert(360);
    int m, h;
    m = h = 0;
    for(int i = 0; i < 720; i++) {
        if(i % 12 == 0) h += 6;
        m += 6;
        m %= 360;
        st.insert(abs(m- h));
        st.insert(abs(360 -  (m - h)));
    }

    int x; 
    while(cin >> x) {
        if(st.count(x)) cout << "Y" << '\n';
        else cout << "N" << '\n';
    }
    return 0;
}