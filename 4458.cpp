#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n; cin >> n;
    cin.ignore();
    for(int i = 0; i < n; i++) {
        string str;
        getline(cin, str);
        if(islower(str[0])) str[0] = toupper(str[0]);
        cout << str << '\n';
    }
    return 0;
}