#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int tc; cin >> tc;
    for(int TC = 1; TC <= tc; TC++) {
        string str; cin >> str;
        int n = str.size();
        vector<pair<char, int>> a;
        for(int i = 0; i < n; i++) {
            int e = i;
            while(str[e] == str[i]) e++;
            if(e == n) {
                while(i != e) {
                    a.push_back({str[i++], 1});
                }
                break;
            }
            
            if(str[e] > str[i]) {
                while(i != e) {
                    a.push_back({str[i++], 2});
                }
                i--;
            } else {
                while(i != e) {
                    a.push_back({str[i++], 1});
                }
                i--;
            }
        }
        
        cout << "Case #" << TC << ": ";
        for(auto &[f, s] : a) {
            for(int i = 0; i < s; i++) {
                cout << f;
            }
        }
        cout << '\n';
    }
    return 0;
}