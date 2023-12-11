#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    bool check[255] = {false};
    int n; cin >> n;
    cin.ignore();
    for(int i = 0; i < n; i++) {
        string str,tmp; 
        getline(cin, str);
        int sz = str.size();
        bool ok = false;
        for(int i = 0; i < sz; i++) {
            if(i == 0 || str[i - 1] == ' ') {
                if(!check[tolower(str[i])]) {
                    check[tolower(str[i])] = ok = true;
                    str = string(str.begin(), str.begin() + i) + "[" + str[i] + "]" + string(str.begin() + i + 1, str.end());
                    break;
                }
            }
        }
        if(!ok) {
            for(int i = 0; i < sz; i++) {
                if(str[i] != ' ' && !check[tolower(str[i])]) {
                    check[tolower(str[i])] = ok = true;
                    str = string(str.begin(), str.begin() + i) + "[" + str[i] + "]" + string(str.begin() + i + 1, str.end());
                    break;
                }
            }
        }
        cout << str << '\n';
    }
    return 0;
}