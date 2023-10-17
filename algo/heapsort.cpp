#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int cnt;
int a[1001];
void fixHeap(int node, int key, int sz) {
    
    
    int now = node;
    while(now <= sz) {
        if(now * 2 + 1 <= sz) {
            cnt += 2;
            int lc = now * 2;
            int rc = now * 2 + 1;
            if(a[lc] > a[rc]) {
                if(a[lc] > a[now]) {
                    int tmp = a[now];
                    a[now] = a[lc];
                    a[lc] = tmp;
                    now = lc;
                } else break;
            } else {
                if(a[rc] > a[now]) {
                    int tmp = a[now];
                    a[now] = a[rc];
                    a[rc] = tmp;
                    now = rc;
                } else break;
            }
        } else if(now * 2 <= sz) {
            int lc = now * 2;
            cnt++;
            if(a[lc] > a[now]) {
                int tmp = a[now];
                a[now] = a[lc];
                a[lc] = tmp;
                now = lc;
            } else break;
        } else break;
    }
}
void heapSort(int n) {
    for(int i = n / 2; i >= 1; i--) {
        fixHeap(i, a[i], n);
    }
    for(int heapsize = n; heapsize >= 2; heapsize--) {
        int Max = a[1];
        a[1] = a[heapsize];
        fixHeap(1,a[heapsize], heapsize - 1);
        a[heapsize] = Max;
    }
}
void solve() {
    for(int i = 0; i < 1001; i++) a[i] = -1;
    cnt = 0;
    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    heapSort(n);
    cout << cnt << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
    return 0;
}