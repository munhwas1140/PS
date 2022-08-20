#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    map<int, int> m;
    cout << m.size() << '\n';
    m[3] = 0;
    cout << m.size() << '\n';
    m[4] += 1;
    cout << m.size() << '\n';
    cout << m[4] << '\n';


    return 0;
}