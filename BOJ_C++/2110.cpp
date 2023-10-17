#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[200000];
int n, c;

int check(int m) {
    int cnt = 1;
    int last = a[0];
    for(int i = 1; i < n; i++) {
        if(a[i] - last >= m) {
            cnt += 1;
            last = a[i];
        }
    }
    return cnt;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> c;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }         

    sort(a, a + n);

    int l = 1;
    int r = 1e9;
    int ans = 0;

    while(l <= r) {
        int m = (l + r) / 2;
        if(check(m) >= c) {
            ans = m;
            l = m + 1;
        } else r = m - 1;
    } 
     
    cout << ans << '\n';

    return 0;
}