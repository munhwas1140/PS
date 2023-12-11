#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n; cin >> n;
    vector<string> a(n);
    set<string> st;
    int idx = -1;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] == "?") idx = i;
        else st.insert(a[i]);
    }
    

    if(n == 1) {
        cin >> n;
        string tmp; cin >> tmp;
        return !(cout << tmp << '\n');
    }

    bool start = false, end = false;
    char stc, edc;

    if(idx == 0) {
        start = true;
        edc = a[idx + 1].front();
    } else if(idx == n - 1) {
        end = true;
        stc = a[idx - 1].back();
    } else {
        edc = a[idx + 1].front();
        stc = a[idx - 1].back();
    }
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        if(st.count(tmp)) continue;
        
        if(start) {
            if(edc == tmp.back()) return !(cout << tmp << '\n');
        } else if(end) {
            if(stc == tmp.front()) return !(cout << tmp << '\n');
        } else {
            if(stc == tmp.front() && edc == tmp.back()) return !(cout << tmp << '\n');
        }
    }
    return 0;
}