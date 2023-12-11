#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[300];

int check(int mid) {
    int cnt = 0;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        if(sum + a[i] > mid) {
            cnt += 1;
            sum = a[i];
        } else {
            sum += a[i];
        }
    }
    return cnt + 1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    
    int l = -1, r = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        l = max(l, a[i]);
        r += a[i];
    } 
    int ans = 0;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(check(mid) <= m) {
            ans = mid;
            r = mid - 1;
        } else  l = mid + 1;
    }

    cout << ans << '\n';
    int sum = 0, cnt = 0;
    for(int i = 0; i < n; i++) {
        sum += a[i];
        if(sum > ans) {
            sum = a[i];
            m--;
            cout << cnt << ' ';
            cnt = 0;
        }
        cnt += 1;
        if(n - i == m) break;
    }
    while(m--) {
        cout << cnt << ' ';
        cnt = 1;
        
    }
    return 0;
}