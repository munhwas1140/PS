#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
int n;
ll k;
int main() {
    fastio;
    cin >> n >> k;
    vector<ll> a(n);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] > 0) pq.push({a[i], i});
    }

    ll sum = 0;
    ll nowk = 0;
    ll remain = 0;
    while(!pq.empty()) {
        if(sum + (pq.top().first - nowk) * (int)pq.size() < k) {
            sum += (pq.top().first - nowk) * (int)pq.size();
            nowk = pq.top().first;
            pq.pop();
        } else {
            nowk += (k - sum) / (int)pq.size();
            remain = (k - sum) % (int)pq.size();
            break;
        }
    }
    vector<ll> ans(n);
    while(!pq.empty()) {
        auto [v, idx] = pq.top();
        pq.pop();
        ans[idx] = a[idx] - nowk;
    }
    ll cnt = 0;
    for(int i = 0; i < n; i++) {
        if(cnt < remain && ans[i] > 0) {
            ans[i]--;
            cnt++;
        }
    }
    for(int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    
    return 0;
}