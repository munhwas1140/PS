#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    string str;
    while(getline(cin, str)) {
        int up, lo, num, sp;
        up = lo = num = sp = 0;
        for(auto &i : str) {
            if(isdigit(i)) num++;
            else if(islower(i)) lo++;
            else if(isupper(i)) up++;
            else sp++;
        }
        cout << lo << ' ' << up << ' ' << num << ' ' << sp << '\n';
    }
    return 0;
}