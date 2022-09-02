#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;

bool solve(){
    int n; cin >> n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        cin >> b[i];
    }
    for(int i=0;i<n;i++){
        if(a[i] > b[i]) return false;
        else if(a[i] == b[i]) continue;
        else{
            int j = (i+1 == n ? 0 : i+1);
            cout << b[j] << ' ' << b[i] << '\n';
            if(b[j]+1 < b[i]) return false;
        }
    }
    return true;
}
 
int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int q; cin >> q;
    while(q--){
        if(solve()){
            cout << "Yes" << "\n";
        }
        else{
            cout << "No" << "\n";
        }
    }
}