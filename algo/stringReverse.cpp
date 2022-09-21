#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
int len(char *str) {
    for(int i = 0; i <= 100; i++) {
        if(!str[i]) return i;
    }
    return -1;
}
void rev(char *str, int s, int e) {
    if(s < e) {
        char tmp = str[s];
        str[s] = str[e];
        str[e] = tmp;
        rev(str, s + 1, e - 1);
    }
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        char str[101] = {0,};
        cin >> str;
        rev(str,0,len(str) - 1);
        cout << str << '\n';
    }
    return 0;
}