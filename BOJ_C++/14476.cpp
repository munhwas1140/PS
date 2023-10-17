#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n; cin >> n;
    vector<int> a(n), s(n), e(n);

    for(int i = 0; i < n; i++) cin >> a[i];

    // 끝점 처리
    s[0] = a[0];
    e[n - 1] = a[n - 1];

    // 누적 최대공약수
    for(int i = 1; i < n; i++) {
        s[i] = gcd(a[i], s[i - 1]);
    }
    for(int i = n - 2; i >= 0; i--) {
        e[i] = gcd(a[i], e[i + 1]);
    }

    // 기본값
    int GCD = s[n - 1]; // a => [0, n - 1] 의 최대공약수
    int idx = -1;

    // 양 끝점 처리
    if(e[1] > GCD) { // a[0]을 제외한 최대공약수
        GCD = e[1];
        idx = 0;
    }
    if(s[n - 2] > GCD) { // a[n - 1]을 제외한 최대공약수
        GCD = s[n - 2];
        idx = n - 1;
    }


    for(int i = 1; i < n - 1; i++) {
        // a[i]를 제외한 최대공약수
        int l = s[i - 1];
        int r = e[i + 1];
        int tmp = gcd(l, r);
        if(tmp > GCD) {
            GCD = tmp;
            idx = i;
        }
    }

    
    if(idx == -1) {
        cout << idx << '\n';
    } else {
        cout << GCD << ' ' << a[idx] << '\n';
    }
    return 0;
}