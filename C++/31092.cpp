#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m, k;
vector<pii> pos[26];
int main() {
    fastio;
    cin >> n >> m >> k;

    vector<tuple<char,int,int>> sticker(m + 1);
    for(int i = 0; i < m; i++) {
        char c; int d, a;
        cin >> c >> d >> a;
        pos[c - 'a'].push_back({d, a});
        sticker[i + 1] = make_tuple(c, d, a);
    }

    vector<int> mp(n);
    for(int i = 0; i < n; i++) {
        cin >> mp[i];
    }

    string str; cin >> str;

    // 맞을경우 -> 그냥 넘어감
    // 틀릴경우 -> (떼고 사서 붙이기), (떼고 다른데서 뗴서 붙이기)


    for(int i = 0; i < n; i++) {
        int now = 0;
        vector<int> have(26);
        for(int j = 0; j < k; j++) {
            auto [c, d, a] = sticker[mp[i + j]];
            if(c == str[j]) continue;
            if(have[str[j] - 'a']) {
                have[str[j] - 'a']--;
                continue;
            }

            now += d; have[c -'a']++;



        }
    }

    return 0;
}