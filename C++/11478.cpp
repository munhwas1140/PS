#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    string str;
    cin >> str;

    int n = str.size();
    set<string> st;
    for(int i = 0; i < n; i++) {
        string tmp = "";
        for(int j = i; j < n; j++) {
            tmp += str[j];
            st.insert(tmp);
        }
    }

    cout << st.size() << '\n';

    return 0;
}