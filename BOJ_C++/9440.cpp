#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n;
void f(vector<int> &a, int idx) {
    for(int i = idx + 1; i < n; i++) {
        if(a[i] != 0) {
            swap(a[i], a[idx]); return ;
        }
    }
}
int main() {
    fastio;
    while(1) {
        cin >> n;
        if(n == 0) break;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int x = 0, y = 0;
        if(a.size() % 2) {
            if(a[0] == 0) f(a, 0);
            if(a[1] == 0) f(a, 1);
        } else {
            if(a[0] == 0) f(a, 0);
            if(a[1] == 0) f(a, 1);
        }
        for(int i = 0; i < n; i++) {
            if(i % 2) x = x * 10 + a[i];
            else y = y * 10 + a[i];
        }
        cout << x + y << '\n';
    }
    return 0;
}