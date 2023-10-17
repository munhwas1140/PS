#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;

    int n; cin >> n;
    priority_queue<ll> mxq;
    priority_queue<ll, vector<ll>, greater<ll>> mnq;
    for(int i = 0; i < n; i++) {
        ll tmp; cin >> tmp;
        if(tmp < 0) mnq.push(tmp);
        else mxq.push(tmp);
    }

    ll ans = 0;
    while((int)mnq.size() >= 1) {
        ll t1, t2;
        t1 = mnq.top(); 
        mnq.pop();
        t2 = mnq.top(); 
        mnq.pop();
        ans += t1 * t2;
    }

    while((int)mxq.size() >= 1 && mxq.top() != 0) {
        ll t1, t2;
        t1 = mxq.top(); mxq.pop();
        t2 = mxq.top(); mxq.pop();
        if(t2 == 0) {
            mxq.push(0);
            ans += t1;
            break;
        }
        ans += t1 * t2;
    }

    if(mnq.size()) {
        if(mxq.size()) {
            if(mxq.top() != 0) {
                ans += mnq.top();
                ans += mxq.top();
            } 
        } else {
            ans += mnq.top();
        }
    }

    cout << ans << '\n';
    return 0;
}