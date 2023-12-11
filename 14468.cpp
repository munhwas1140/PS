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

    int ans = 0;
    for(int i = 0; i < 26; i++) {
        int cnt[26] = {0};
        char now = char('A' + i);
        int it = 0;
        while(str[it] != now) it++;

        it++;
        while(it < n && str[it] != now) {
            cnt[str[it] - 'A'] ^= 1;
            it++;
        }

        for(int j = 0; j < 26; j++) {
            if(j != i && cnt[j]) ans++;
        }
    }
    cout << ans / 2 << '\n';
    return 0;
}