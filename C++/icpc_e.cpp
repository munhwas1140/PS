#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, a;
ll b;
ll arr[100000];
int main() {
    fastio;
    cin >> n >> b >> a;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i] /= 2;
    }
    sort(arr, arr + n);
    int s, e;
    s = e = 0;
    ll sum = 0;
    int ans = 0;
    while(e < n) {
        if(e >= a) {
            sum += arr[s++];
            sum += arr[e++];
        } else {
            sum += arr[e++];
        }
        if(sum <= b) ans = e;
    }
    cout << ans << '\n';
    return 0;
}