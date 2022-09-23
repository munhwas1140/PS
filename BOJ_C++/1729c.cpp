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
    int tc; cin >> tc;
    while(tc--) {
        string str; cin >> str;
        int n = str.size();
        vector<pair<int,int>> a;
        if(str[0] > str[n - 1]) {
            for(int i = 1; i < n - 1; i++) {
                if(str[i] <= str[0] && str[i] >= str[n - 1]) {
                    a.push_back({str[i] - 'a', i + 1});
                }
            }
            sort(a.rbegin(), a.rend());
        } else {
            for(int i = 1; i < n - 1; i++) {
                if(str[i] >= str[0] && str[i] <= str[n - 1]) {
                    a.push_back({str[i] - 'a', i + 1});
                }
            }
            sort(a.begin(), a.end());
        }
        cout << abs(str[0] - str[n - 1]) << ' ' << a.size() + 2 << '\n';
        cout << 1 << ' ';
        for(int i = 0; i < a.size(); i++) {
            cout << a[i].second << ' ';
        }
        cout << n << '\n';
    }

    return 0;
}