#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        vector<string> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int k = a[0].size();
        vector<bool> check(n, true);
        for(int i = 0; i < k; i++) {
            set<char> st;
            for(int j = 0; j < n; j++) {
                if(!check[j]) continue;
                st.insert(a[j][i]);
            }
            
            if(st.size() != 2) continue;
            char remove;
            auto it = st.begin();
            char t1 = *it;
            it++;
            char t2 = *it;
            if(t1 == 'P') {
                if(t2 == 'R') remove = 'R';
                else remove = 'P';
            } else {
                remove = 'S';
            }

            for(int j = 0; j < n; j++) {
                if(a[j][i] == remove) check[j] = false;
            }
        }
        set<int> st;
        for(int i = 0; i < n; i++) {
            if(check[i]) st.insert(i);
        }
        if(st.size() == 1) {
            cout << *(st.begin()) + 1 << '\n';
        } else cout << 0 << '\n';

    }

    return 0;
}