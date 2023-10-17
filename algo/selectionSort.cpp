#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE 1000
void Sort(int *a, int n) {
    int comp = 0, swap = 0;
    for(int i = 0; i < n - 1; i++) {
        int tmp = i;
        for(int j = i + 1; j < n; j++) {
            if(++comp && a[tmp] > a[j]) {
                tmp = j;
            }
        }
        if(tmp != i) {
            swap++;
            std::swap(a[i], a[tmp]);
        }
    }
    cout << comp << ' ' << swap << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int tc;
    cin >> tc;
    while(tc--) {
        int n; cin >> n;
        int a[MAX_SIZE];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        Sort(a, n);
    }
}
