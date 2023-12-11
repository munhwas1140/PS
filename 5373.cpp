#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)
using ll = long long;
vector<vector<char>> a[6]; 
int opi[255];
void init() {
    char tmp[] = {'w','y','r','o','g','b'};
    for(int i = 0; i < 6; i=+) {
        a[i] = vector<vector<char>> (3, vector<char>(3, tmp[i]));
    }
}
int main() {
    fastio;
    opi['U'] = 0;
    opi['D'] = 1;
    opi['F'] = 2;
    opi['B'] = 3;
    opi['L'] = 4;
    opi['R'] = 5;
    int tc;
    cin >> tc;
    while(tc--) {
        init();
        int n;
        cin >> n;
        string op;
        while(n--) {
            cin >> op;
            int pos = opi[op[0]];
            int cnt = (op[1] == '+' ? 1 : 3);
            // 위, 아, 앞, 뒷, 왼, 오;
            // 앞 시계  위(3행), 오(1열), 아(1행) , 왼(3열) 오른쪽으로 한칸ㅅ씩 로테이션
            // 아래 시계 앞(3생), 오른쪽(3행), 뒤(3행), 왼(3행)
            // 위 시계 앞(1행), 왼(1행), 뒤(1행), 오른(1행);
            // 뒷 시계 위(1행), 왼(1열), 아래(3행), 오른(3열);
            // 왼 시계 위(1열), 
            
        }

    }
      
    return 0;
}