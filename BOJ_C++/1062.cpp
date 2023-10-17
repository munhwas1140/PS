#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int word[51];
int n, k;
int go(int state, int x, int idx) {
    if(x == 0) {
        int ret = 0;
        for(int i = 0; i < n; i++) {
            if((word[i] & state) == word[i]) ret++;
        }
        return ret;
    }

    int ans = 0;
    for(int i = idx + 1; i < 26; i++) {
        if(state & (1 << i)) continue;
        ans = max(ans, go(state | (1 << i), x - 1, i));
    }
    return ans;
}
int main() {
    fastio;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        string str; cin >> str;
        for(char c : str) {
            word[i] |= 1 << (c -'a');
        }
    }

    if(k < 5) cout << 0 << '\n';
    else {
        string tmp = "antic";
        int state = 0;
        for(int i = 0; i < 5; i++) {
            state |= (1 << (tmp[i] - 'a'));
        }

        cout << go(state, k - 5, -1) << '\n';
    }
    return 0;
}