#include <bits/stdc++.h>
using namespace std;

int n, m, total, cnt;
char board[502][502], cpy[502][502];
pair<int, int> bulb[2];
char bulbDir[4] = {'^', '>', 'v', '<'};

void copyBoard(){
    for(int i = 0; i <= n + 1; i++)
        for(int j = 0; j <= m + 1; j++) board[i][j] = cpy[i][j];
}
bool D(int x, int y){
    char ch = board[x][y];
    if(ch == 'l' || ch == 'q' || ch == 'p' || ch == 'v')
        return true;
    return false;
}
bool R(int x, int y){
    char ch = board[x][y];
    if(ch == '-' || ch == 'p' || ch == 'b' || ch == '>')
        return true;
    return false;
}
bool U(int x, int y){
    char ch = board[x][y];
    if(ch == 'l' || ch == 'd' || ch == 'b' || ch == '^')
        return true;
    return false;
}
bool L(int x, int y){
    char ch = board[x][y];
    if(ch == '-' || ch == 'd' || ch == 'q' || ch == '<')
        return true;
    return false;
}
void dfs(int x, int y, char dir){
    cnt++;
    if(x == bulb[1].first && y == bulb[1].second) return;

    char ch = board[x][y];
    if(D(x - 1, y)) 
        if(ch == '^' || (ch == 'd' && dir == '>') || (ch == 'b' && dir == '<') || (ch == 'l' && dir == '^'))
            dfs(x - 1, y, '^');
            
    if(U(x + 1, y))
        if(ch == 'v' || (ch == 'q' && dir == '>') || (ch == 'p' && dir == '<') || (ch == 'l' && dir == 'v'))
            dfs(x + 1, y, 'v');
    
    if(R(x, y - 1))
        if(ch == '<' || (ch == 'd' && dir == 'v') || (ch == 'q' && dir == '^') || (ch == '-' && dir == '<'))
            dfs(x, y - 1, '<');

    if(L(x, y + 1))
        if(ch == '>' || (ch == 'p' && dir == '^') || (ch == 'b' && dir == 'v') || (ch == '-' && dir == '>'))
            dfs(x, y + 1, '>');
}
bool possible(){
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) {
            
            char& ch = board[i][j];
            if(D(i - 1, j) && R(i, j - 1)) 
                if(ch == 'q') ch = 'd';
                else return false;
            
            if(D(i - 1, j) && !R(i, j - 1))
                if(ch == 'q') ch = 'b';
                else if(ch == 'l') ch = 'l';
                else if(ch == '^') ch = '^';
                else return false;
            
            if(!D(i - 1, j) && R(i, j - 1))
                if(ch == 'q') ch = 'q';
                else if(ch == 'l') ch = '-';
                else if(ch == '<') ch = '<';
                else return false;
            
            if(!D(i - 1, j) && !R(i, j - 1))
                if(ch == 'q') ch = 'p';
                else if(ch == '-' || ch == '<' || ch == '^') return false; 
        }
    
    cnt = 0;
    dfs(bulb[0].first, bulb[0].second, '.');
    if(cnt == total) return true;
    return false;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        memset(cpy, '*', sizeof(cpy));
        total = 0;
        int bb = 0;
        cin >> n >> m;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++) {
                cin >> cpy[i][j];
                if(cpy[i][j] != '*') total++;
                if(cpy[i][j] == 'O') bulb[bb++] = {i, j};
            }
        
        bool ok = false;
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                copyBoard();
                board[bulb[0].first][bulb[0].second] = bulbDir[i];
                board[bulb[1].first][bulb[1].second] = bulbDir[j];
                if(possible()){
                    ok = true;
                    break;
                }
            }
            if(ok) break;
        }

        if(ok){
            cout << "YES" << '\n';
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++) cout << board[i][j];
                cout << '\n';
            }
        }else cout << "NO" << '\n';
    }
    return 0;
}