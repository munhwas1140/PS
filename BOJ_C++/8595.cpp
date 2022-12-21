#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    int n;
    long long sum = 0;
    string str;
    cin >> n >> str;
    for(auto &i : str) if(!isdigit(i)) i = ' ';
    
    istringstream in(str);
    while(in >> n) sum += n;
    cout << sum << '\n';
    return 0;
}