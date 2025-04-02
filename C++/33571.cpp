#include <bits/stdc++.h>

#include <string>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int cnt[255];
int main() {
    fastio;
    char one_list[] = {'A', 'a', 'b', 'D', 'd', 'e', 'g', 'O',
                       'o', 'P', 'p', 'Q', 'q', 'R', '@'};
    for (char one : one_list) {
        cnt[one] = 1;
    }
    cnt['B'] = 2;

    string str;
    getline(cin, str);

    int ans = 0;
    for (char c : str) {
        ans += cnt[c];
    }
    cout << ans << '\n';

    return 0;
}