#include <iostream>
using namespace std;
int n;
int *check(int *a, int s, int e) {
    if(s == e) {
        int *tmp = new int[2];
        tmp[0] = a[s];
        tmp[1] = -1;
        return tmp;
    }

    int m = (s + e) / 2;
    int *t1 = check(a, s, m);
    int *t2 = check(a, m + 1, e);
    
    int *tmp = new int[2];
    if(t1[0] == t2[0]) {
        tmp[0] = tmp[1] = t1[0];
    } else if(t1[0] > t2[0]) {
        tmp[0] = t1[0];
        if(t1[1] > t2[0]) tmp[1] = t1[1];
        else tmp[1] = t2[0];
    } else {
        tmp[0] = t2[0];
        if(t2[1] > t1[0]) tmp[1] = t2[1];
        else tmp[1] = t1[0];
    }

    delete[] t1;
    delete[] t2;
    
    return tmp;
}
void solve() {
    cin >> n;
    int *a = new int[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    int *ans = check(a, 0, n - 1); // {first, second}
    cout << ans[1] << '\n';

    delete[] a;
    delete[] ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc;
    while(tc--) {
        solve();
    }
}