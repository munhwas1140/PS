#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define MAX_SIZE 1000
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void Sort(int *a, int n) {
    int comp = 0, swap = 0;
    int shrink = 2;
    int gap = n / shrink;
    int i, j;
    while(gap > 0) {
        for(i = gap; i < n; i++) {
            int tmp = a[i];
            for(j = i; (j >= gap) && ++comp && (a[j - gap] > tmp); j -= gap) {
                a[j] = a[j - gap];
                swap++;
            }
            a[j] = tmp;
        }
        gap /= shrink;
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