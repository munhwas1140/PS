#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ull = unsigned long long;
int ctoi[256];
ll go(string str) {
    ll ret = 0;
    for(int i = 0; i < str.size(); i++) {
        ret += ctoi[str[str.size() - 1 - i]] * (ll)pow(16, i);
    }
    return ret;
}
int main() {
    fastio;
    for(char i = '0'; i <= '9'; i++) {
        ctoi[i] = i - '0';
    }
    for(char i = 'a'; i <= 'f'; i++) {
        ctoi[i] = i - 'a' + 10;
    }
    string str; cin >> str;
    int n; cin >> n;
    vector<string> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int idx = 0;
    for(int i = 0; i < n; i++) {
        string tmp;
        if(a[i] == "char") {
            tmp = str.substr(idx, 2);
            idx += 2;
        } else if(a[i] == "int") {
            tmp = str.substr(idx, 8);
            idx += 8;
        } else if(a[i] == "long_long") {
            tmp = str.substr(idx, 16);
            idx += 16;
        }
        cout << go(tmp) << ' ';
    }
    cout << '\n';
    return 0;
}
