#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int cnt[7];
int check(int idx) {
    if(idx <= 5) {
        return 2 * (idx + 1) + cnt[idx + 1] * (idx + 1);
    }
    if(idx == 6) {
        for(int i = 6; i >= 1; i--) {
            if(cnt[i] >= 2) return i * 4;
        }
        return 0;
    }
    if(idx == 7) {
        for(int i = 1; i <= 6; i++) {
            if(cnt[i] == 3) {
                if(i == 6) return 18 + 10;
                else return i * 3 + 12;
            }
        }
        for(int i = 1; i <= 6; i++) {
            if(cnt[i] == 2) {
                for(int j = 1; j <= 6; j++) {
                    if(cnt[j] == 1) {
                        if(i > j) {
                            return i * 3 + 2 * j;
                        } else return i * 2 + 3 * j;
                    }
                }
            }
        }
        return 0;
    }
    if(idx == 8) {
        int t = 0;
        for(int i = 1; i <= 5; i++) {
            if(cnt[i]) t++;
        }
        if(t >= 3) return 30;
        else return 0;
    }
    if(idx == 9) {
        int t = 0;
        for(int i = 2; i <= 6; i++) {
            if(cnt[i]) t++;
        }
        if(t >= 3) return 30;
        return 0;
    }

    if(idx == 10) {
        for(int i = 1; i <= 6; i++) {
            if(cnt[i] == 3) return 50;
        }
        return 0;
    }

    if(idx == 11) {
        int ret = 0;
        for(int i = 1; i <= 6; i++) {
            ret += i * cnt[i];
        }
        return ret + 12;
    }
    return 0;
}
int main() {
    fastio;
    string str; cin >> str;
    for(int i = 0; i < 3; i++) {
        int tmp; cin >> tmp;
        cnt[tmp]++;
    }
    int ans = 0;
    for(int i = 0; i < 12; i++) {
        if(str[i] == 'Y') ans = max(ans, check(i));
    }
    cout << ans << '\n';
    return 0;
}