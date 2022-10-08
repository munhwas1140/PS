#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int cnt = 0;
void Merge(vector<int> &a, int s, int m, int e) {
    int i, j, k;
    int tmp[101];
    for(i = s; i <= e; i++) {
        tmp[i] = a[i];
    }
    i = k = s;
    j = m + 1;
    while(i <= m && j <= e) {
        if(++cnt && tmp[i] <= tmp[j]) {
            a[k++] = tmp[i++];
        } else {
            a[k++] = tmp[j++];
        }
    }
    while(i <= m) {
        a[k++] = tmp[i++];
    }
    while(j <= e) {
        a[k++] = tmp[j++];
    }
}
void mergesort(vector<int> &a, int s, int e) {
    if(s == e) return ;
    int m = (s + e) / 2;
    mergesort(a,s,m);
    mergesort(a,m+1,e);
    Merge(a,s, m, e);
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cnt = 0;
        mergesort(a,0,n-1);
        cout << cnt << '\n';
    }

    return 0;
}