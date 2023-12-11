#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
// S, E, N, W
string a[3][4] =
{
    {
        ".OP.",
        "O..P",
        ".PO.",
        "P..O"
    },
    {
        "I..P",
        ".PI.",
        "P..I",
        ".IP."
    },
    {
        "O..P",
        ".PO.",
        "P..O",
        ".OP."
    }
};
int main() {
    fastio;
    char dir;
    cin >> dir;
    string str = "";
    for(int i = 0; i < 2; i++) {
        string tmp; cin >> tmp;
        str += tmp;
    }

    int x;
    if(dir == 'S') x = 0;
    else if(dir == 'E') x = 1;
    else if(dir == 'N') x = 2;
    else x = 3;

    for(int i = 0; i < 3; i++) {
        if(str == a[i][x]) {
            if(i == 0) cout << 'T' << '\n';
            else if(i == 1) cout << 'F' << '\n';
            else cout << "Lz" << '\n';
            return 0;
        }
    }
    cout << '?' << '\n';
    return 0;
}