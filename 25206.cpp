#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    fastio;
    double sum = 0;
    double grsum = 0;
    for(int i = 0; i < 20; i++) {
        string str; cin >> str;
        double cost; cin >> cost;
        string gr; cin >> gr;
        double get = 0.0;
        
        if(gr == "P") continue;
        else if(gr == "A+") get += 4.5;
        else if(gr == "A0") get += 4.0;
        else if(gr == "B+") get += 3.5;
        else if(gr == "B0") get += 3.0;
        else if(gr == "C+") get += 2.5;
        else if(gr == "C0") get += 2.0;
        else if(gr == "D+") get += 1.5;
        else if(gr == "D0") get += 1.0;
        else if(gr == "F") get += 0.0;
        sum += cost;
        grsum += get * cost;
    }

    cout << fixed << setprecision(6);
    cout << grsum / sum << '\n';

    return 0;
}