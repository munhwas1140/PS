#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int cnt[26];
int main() {
    fastio;
    string str;
    cin >> str;
    int n = str.size();
    for(int i = 0; i < n; i++) {
        cnt[str[i] - 'A']++;
    }  
    if(n % 2) {
        int idx = -1;
        for(int i = 0; i < 26; i++) {
            if(cnt[i] % 2) {
                if(idx == -1) {
                    idx = i;
                } else {
                    return !(cout << "I'm Sorry Hansoo");
                }
            }
        }

        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < cnt[i] / 2; j++) {
                cout << char('A' + i);
            }
        }
        cout << char('A' + idx);
        for(int i = 26; i >= 0; i--) {
            for(int j = 0; j < cnt[i] / 2; j++) {
                cout << char('A' + i);
            }
        }
        cout << '\n';
    } else {
        for(int i = 0; i < 26; i++) {
            if(cnt[i] % 2) {
                return !(cout << "I'm Sorry Hansoo");
            }
        }
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < cnt[i] / 2; j++) {
                cout << char('A' + i);
            }
        }
        for(int i = 26; i >= 0; i--) {
            for(int j = 0; j < cnt[i] / 2; j++) {
                cout << char('A' + i);
            }
        }
        cout << '\n';
    }
    return 0;
}