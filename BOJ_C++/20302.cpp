#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n; cin >> n;
    vector<int> p(100001, -1);

    for(int i = 2; i <= 100000; i++) {
        if(p[i] == -1) {
            for(int j = i; j <= 100000; j += i) {
                if(p[j] == -1) p[j] = i;
            }
        }
    }
    vector<int> sum(100001, 0);

    int tmp; cin >> tmp;
    
    bool zero = false;
    if(tmp == 0) zero = true;
    if(tmp < 0) tmp = -tmp;
    while(zero == false && tmp != 1) {
        sum[p[tmp]]++;
        tmp /= p[tmp];
    }

    for(int i = 0; i < n - 1; i++) {
        char op;
        cin >> op >> tmp;

        if(tmp == 0) zero = true;
        if(zero == true) continue;

        if(tmp < 0) tmp = -tmp;

        if(op == '/') {
            while(tmp != 1) {
                sum[p[tmp]]--;
                tmp /= p[tmp];
            }
        } else {
            while(zero == false && tmp != 1) {
                sum[p[tmp]]++;
                tmp /= p[tmp];
            }
        }
    }

    if(zero == true) cout << "mint chocolate" << '\n';
    else {
        for(int i = 2; i <= 100000; i++) {
            if(sum[i] < 0) {
                return !(cout << "toothpaste" << '\n');
            }
        }
        cout << "mint chocolate" << '\n';
    }

    return 0;
}