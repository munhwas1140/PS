#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n, k;
    cin >> n >> k;
    vector<string> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end(), [&] (const string &u, const string &v) {
        if(u.size() == v.size()) return u < v;
        return u.size() < v.size();
    });
    string mx = a.back();

    for(int i = 0; i < n; i++) {
        int idx = i;
        for(int j = i + 1; j < n; j++) {
            bool ok = false;
            int num = min(a[idx].size(), a[j].size());
            for(int k = 0; k < num; k++) {
                if(a[idx][k] > a[j][k]) {
                    ok = true;
                    idx = j;
                    break;
                }
            }
            if(!ok) {
                if(a[idx].size() > a[j].size()) {
                    for(int k = num; k < a[idx].size(); k++) {
                        if(a[idx][k] >= a[j][0]) {
                            idx = j;
                            break;
                        }
                    }
                } else {
                    for(int k = num; k < a[j].size(); k++) {
                        if(a[idx][0] <= a[j][k]) {
                            idx = j;
                            break;
                        }
                    }
                }
            }
        }
        
        

        swap(a[i], a[idx]);
        
    }

    
    for(int i = n - 1; i >= 0; i--) {
        cout << a[i];
        if(a[i] == mx) {
            for(int j = 0; j < k - n; j++) {
                cout << a[i];
            }
        }
    }

    return 0;
}