#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define MAX_SIZE 1000

void Sort(int *a, int n) {
    int comp = 0, swap = 0;
    for(int i = 1; i < n; i++) {
        int tmp = a[i];
        int j;
        for(j = 1; j <= i; j++) {
            if(++comp && a[i - j] > tmp) {
                a[i - j + 1] = a[i - j];
                swap++;
            } else break;
        }

        if(j != 1) {
            a[i - j + 1] = tmp;
        }
    }
    cout << comp << ' ' << swap << '\n';
}
int main() {
    fastio;
    int tc; 
    cin >> tc;
    while(tc--) {
        int n; cin >> n;
        int a[MAX_SIZE];
        for(int i = 0; i < n; i++) cin >> a[i];
        Sort(a, n);
    }
      
    return 0;
}