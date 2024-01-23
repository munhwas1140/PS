#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, cnt[10];
string str;
vector<int> ans;

bool go(int idx) {
    if(idx == n / 2) {
        if(n % 2) {
            int now = str[n / 2] - '0';
            for(int i = 9; i > now; i--) {
                if(cnt[i]) {
                    now = i;
                    break;
                }
            }
            ans.push_back(now);
        }
        return true;
    }

    for(int i = 9; i >= 1; i--) {
        bool f = false;
        if(str[idx] == i + '0') {
            if(str[n - 1 - idx] == i + '0') {
                f = go(idx + 1);
            } else {
                if(cnt[i]) {
                    cnt[i]--;
                    f = go(idx + 1);
                    cnt[i]++;
                }
            }
        } else {
            if(cnt[i]) {
                cnt[i]--;
                if(str[n - 1 - idx] == i + '0') {
                    f = go(idx + 1);
                } else {
                    if(cnt[i]) {
                        cnt[i]--;
                        f = go(idx + 1);
                        cnt[i]++;
                    }
                }
                cnt[i]++;
            }
        }
        if(f) {
            ans.push_back(i);
            return f;
        }
    }
    return true;
}

int main() {
    fastio;
    cin >> n >> str;
    for(int i = 0; i < n; i++) {
        cnt[str[i] - '0']++;
    }

    go(0);

    for(int i = (int)ans.size() - 1; i >= 0; i--) {
        cout << ans[i];
    }
    if(n % 2 == 0) cout << ans[0];
    for(int i = 1; i < ans.size(); i++) {
        cout << ans[i];
    }

    return 0;
}