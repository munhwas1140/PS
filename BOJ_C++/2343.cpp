#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100000];
int n, m;

int check(int mid) {
    int sum = 0, cnt = 1;
    for(int i = 0; i < n; i++) {
        if(sum + a[i] > mid) {
            cnt += 1;
            sum = a[i];
        } else sum += a[i];
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int l = 0, r = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        l = max(l, a[i]);
        r += a[i];
    }

    int ans;
    
    while(l <= r) {
        int mid = (l + r) / 2;
        int c = check(mid);
        if(c <= m) {
            r = mid - 1;
            ans = mid;
        } else l = mid + 1;
    }

    cout << ans << '\n';

    return 0;
}