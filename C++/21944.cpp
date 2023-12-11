#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
struct asdf{ 
    int id;
    int diff;
    asdf (int id, int diff) : id(id), diff(diff) {}
    bool operator<(const asdf &t) const {
        if(diff == t.diff) {
            return id < t.id;
        }
        return diff < t.diff;
    }
};

int n, m;
set<asdf> st;
set<asdf> cate[101];
map<int, pii> mp;
int main() {
    fastio;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int p, l, g;
        cin >> p >> l >> g;
        mp[p] = {l, g};
        st.insert(asdf(p, l));
        cate[g].insert(asdf(p, l));
    }

    cin >> m;
    while(m--) {
        string str; cin >> str;

        if(str == "add") {
            int p, l, g;
            cin >> p >> l >> g;
            mp[p] = {l, g};
            st.insert(asdf(p, l));
            cate[g].insert(asdf(p, l));
        } else if(str == "recommend") {
            int g, x;
            cin >> g >> x;
            if(x == 1) {
                auto it = cate[g].end();
                it--;
                cout << it->id << '\n';
            } else {
                auto it = cate[g].begin();
                cout << it->id << '\n';
            }
        } else if(str == "recommend2") {
            int x; cin >> x;
            if(x == 1) {
                auto it = st.end();
                it--;
                cout << it->id << '\n';

            } else {
                auto it = st.begin();
                cout << it->id << '\n';
            }
        } else if(str == "recommend3") {
            int x, l;
            cin >> x >> l;
            if(x == 1) {
                auto it = st.lower_bound(asdf(0, l));
                if(it == st.end()) {
                    cout << -1 << '\n';
                } else {
                    cout << it->id << '\n';
                }
            } else {
                auto it = st.upper_bound(asdf(0, l));
                if(it == st.begin()) {
                    cout << -1 << '\n';
                } else {
                    it--;
                    cout << it->id << '\n';
                }
            }
        } else if(str == "solved") {
            int p; cin >> p;
            int l = mp[p].first;
            int g = mp[p].second;
            cate[g].erase(asdf(p, l));
            st.erase(asdf(p, l));
        }
    }

    return 0;
}