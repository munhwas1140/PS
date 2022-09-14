#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define MAX_SIZE 1000
void Swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void Sort(int *a, int n) {
    int comp = 0, swap = 0;
    
    int gap = n;
    double shrink = 1.3;
    bool sorted = false;

    while(!sorted) {
        gap = (int)floor(gap/shrink);
        if(gap <= 1) {
            gap = 1;
            sorted = true;
        }

        int i = 0;
        while(i + gap < n) {
            if(++comp && a[i] > a[i + gap]) {
                swap++;
                Swap(&a[i], &a[i + gap]);
                sorted = false;
            }
            i += 1;
        }
    }
    cout << comp << ' ' << swap << '\n';
}
int main() {
    fastio;
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        int a[MAX_SIZE];
        for(int i = 0; i < n; i++) cin >> a[i];
        Sort(a, n);
    }     
      
    return 0;
}