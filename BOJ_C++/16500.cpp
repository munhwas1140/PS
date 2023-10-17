#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[101];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string str;
    int n;

    cin >> str >> n;
    vector<string> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }     
    sort(a.begin(), a.end());
    dp[0] = 1;

    for(int i = 0; i < str.size(); i++) {
        for(int j = 0; j <= str.size() - i; j++) {
            if(dp[i]) {
                auto it = find(a.begin(), a.end(), str.substr(i,j));
                if(it != a.end()) dp[i+j] = 1;
            }
        }
    }
    cout << dp[str.size()] << '\n';

    return 0;
}