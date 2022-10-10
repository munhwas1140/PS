#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
ll sum[200001];
int main() {
    fastio;
    int n; cin >> n;
    vector<int> a(n + 1);
    queue<int> q;
    ll ans = n;
    ll pre = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        ll t = q.size();
        if(t >= a[i]) {
            if(t >= 2) {
                t -= pre;
                if(pre > 0) ans += pre * t;
                if(t >= 2) ans += (t * (t - 1)) / 2;
            }
            while(q.size() >= a[i]) {
                q.pop();
            }
            pre = q.size();
        }
        q.push(a[i]);
        
        sum[i] = ans - (n - i);
        t = q.size();
        if(t >= 2) {
            t -= pre;
            if(pre > 0) sum[i] += pre * t;
            sum[i] += (t * (t - 1)) / 2;
        }
    }

    ll t = q.size();
    if(t >= 2) {
        t -= pre;
        if(pre > 0) ans += pre * t;
        ans += (t * (t -1)) / 2;
    }
    sum[n] = ans;

    int qq; cin >> qq;
    while(qq--) {
        int x, y;
        cin >> x >> y ;
        cout << sum[y] - sum[x] << '\n';
    }

    for(int i = 0; i <= n; i++) {
        cout << sum[i] << ' ';
    }
    cout << '\n';
    return 0;
}