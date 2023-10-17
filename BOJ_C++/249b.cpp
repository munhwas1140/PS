#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;

int main() {
    fastio;
    int check[256] = {0};
    string str;
    cin >> str;

    bool ok = true;
    for(int i = 0; i < str.size(); i++) {
        check[str[i]]++;
        if(check[str[i]] > 1) ok = false;
    }
    if(!ok) return !(cout << "No" << '\n');

    ok = false;
    for(int i = 'A'; i <= 'Z'; i++) {
        if(check[i]) ok = true;
    }
    if(!ok) return !(cout << "No" << '\n');
    ok = false;
    for(int i = 'a'; i <= 'z'; i++) {
        if(check[i]) ok = true;
    }
    if(!ok) return !(cout << "No" << '\n');
    cout << "Yes" << '\n';
    return 0;
}