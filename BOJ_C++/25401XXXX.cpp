#include <bits/stdc++.h>
using namespace std;

int a[500];
int diff[500];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n - 1; i++) {
        diff[i] = diff[i+1] - diff[i];
    }
    
     
    return 0;
}