#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        vector<int> pos;
        pos.push_back(1);
        int sum = 1;
        for(int i = 2; i * i <= n; i++) {
            if(n % i == 0) {
                pos.push_back(i);
                sum += i;
                if(i * i != n) {
                    pos.push_back(n / i);
                    sum += n / i;
                }
            }
        }

        if(sum <= n) {
            cout << "BOJ 2022" << '\n';
            continue;
        }

        bool ok = true;
        for(int x : pos) {
            int tmp = 1;
            for(int i = 2; i * i <= x; i++) {
                if(x % i == 0) {
                    tmp += i;
                    if(i * i != x) tmp += x / i;
                }
            }
            if(tmp > x) {
                ok = false;
            }
        }
        if(ok) cout << "Good Bye" << '\n';
        else cout << "BOJ 2022" << '\n';
    }

    return 0;
}