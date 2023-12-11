#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

int a[100000];
int cnt[2000001];
int main() {
    fastio;
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    } 
    int x;
    cin >> x;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(x - a[i] >= 0) ans += cnt[x - a[i]];
        cnt[a[i]]++;
    }
    cout << ans << '\n';
      
    return 0;
}