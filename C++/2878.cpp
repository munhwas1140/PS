#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int main() {
    fastio;
    int m, n;
    cin >> m >> n;
    vector<ull> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    ull s = 0, e = 2e9;
    ull ans = 0;

    while(s <= e) {
        cout << s << ' ' << e << '\n';
        ull mid = (s + e) / 2;

        int now = m;
        ull tmp = 0;
        priority_queue<ull> pq;
        bool f = true;
        for(int i = 0; i < n; i++) {
            if(a[i] <= mid) {
                now -= a[i];
            } else {
                pq.push(a[i] - mid);
                now -= mid;
                tmp += (a[i] - mid) * (a[i] - mid);
            }
            if(now < 0) {
                f = false;
                break;
            }
        }


        if(f) {
            if(now) {
                while(!pq.empty() && pq.top() != 0 && now) {
                    ull top = pq.top();
                    pq.pop();
                    tmp -= top * top;
                    tmp += (top - 1) * (top - 1);
                    top--;
                    pq.push(top);
                    now--;
                }
            }
            if(ans == 0 || ans > tmp) {
                ans = tmp;
            }
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    cout << ans << '\n';
    return 0;
}