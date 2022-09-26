#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;

int main() {
    fastio;
    string str; cin >> str;
    if(str[0] == '1') {
        cout << "No" << '\n';
    } else {
        int toCol[10] = {3,2,4,1,3,5,0,2,4,6};
        int cnt[7] = {1,1,2,2,2,1,1};
        
        for(int i = 0; i < 10; i++) {
            if(str[i] == '0') {
                cnt[toCol[i]]--;
            }
        }
        
        bool ok = false;
        for(int i = 0; i < 7; i++) {
            for(int j = i + 1; j < 7; j++) {
                for(int k = j + 1; k < 7; k++) {
                    if(cnt[i] > 0 && cnt[j] == 0 && cnt[k] > 0) {
                        ok = true;
                        break;
                    }
                }
            }
        }
        if(ok) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }

    return 0;
}