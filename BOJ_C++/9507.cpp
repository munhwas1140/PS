#include <bits/stdc++.h>
using namespace std;
long long dp[68];

long long fi(int n) {
    if(n < 2) return 1;
    else if(n == 2) return 2;
    else if(n == 3) return 4;
    
    long long &ans = dp[n];
    if(ans != 0) return ans;
    
    ans = fi(n-1) + fi(n-2) + fi(n-3) + fi(n-4);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    while(tc--) {
        int n;
        cin >> n;
        cout << fi(n) << '\n';
    }

    return 0;
}