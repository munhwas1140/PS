#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
int n;
int a[4];
int main() {
    fastio;
    cin >> n;
    int ans = 0;
    queue<int> q;
    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        int qsz = q.size();
        for(int j = 0; j < qsz; j++) {
            int now = q.front();
            q.pop();
            now += tmp;
            if(now >= 4) {
                ans++;
            } else {
                q.push(now);
            }
        }
        if(tmp == 4) ans++;
        else q.push(tmp);
    }
    cout << ans << '\n';

    return 0;
}