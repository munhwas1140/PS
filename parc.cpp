#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void solve() {
    int n; cin >> n;
    string str;
    cin >> str;
    string ans = "0";
    int st;
    for(int i = 0; i < n; i++) {
        if(str[i] == '1') {
            ans = str.substr(i);
            st = i;
            break;
        }
    }

    if(ans == "0") {//no ans
        cout << ans << '\n';
        return ;
    }

    vector<int> anszero;
    for(int i = 0; i < ans.size(); i++) {
        if(ans[i] == '0') anszero.push_back(i);
    }
    vector<bool> check(anszero.size(), false);

    if(anszero.empty()) { //all one
        cout << ans << '\n';
        return ;
    }

    
    vector<int> ones;
    for(int i = st; i < n; i++) {
        if(str[i] == '1') {
            ones.push_back(i);
        }
    }

    for(int i = 0; i < ones.size(); i++) {
        int diff = ones[i] - anszero.front();
        int it = 0;
        for(int j = i; j < ones.size(); j++) {
            int now = ones[j] - diff;
            if(now > anszero[it]) {
                bool ok = false;
                while(it < anszero.size() && now > anszero[it]) {
                    if(check[it])  {
                        ok = true;
                        break;
                    }
                    it++;
                }
                if(ok) break; 
            }
            if(it > anszero.size()) break;
            if(anszero[it] == now) {
                if(check[it] == false) {
                    check[it] = true;
                    for(int k = it + 1; k < check.size(); k++) check[k] = false;
                }
                it++;
            }
            if(it > anszero.size()) break;
        }
    }

    
    for(int i = 0; i < anszero.size(); i++) {
        if(check[i]) ans[anszero[i]] = '1';
    }
    cout << ans << '\n';
}
int main() {
    fastio;
    solve();
    return 0;
}