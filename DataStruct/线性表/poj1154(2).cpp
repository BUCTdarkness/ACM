#include<iostream>
#include<string.h>
using namespace std;
const int Max = 30;

int row, col, ans = 0;
char map[Max][Max];
bool vis[Max];
int dr[4] = {-1, 0, 0, 1};
int dc[4] = {0, -1, 1, 0};



bool inmap(int r, int c){
    if(r >= 1 && r <= row && c >= 1 && c <= col)
        return true;
    return false;
}

 

void dfs(int dep, int now_r, int now_c){
    if(dep > ans) ans = dep;
    for(int i = 0; i < 4; i ++){
        int r = now_r + dr[i];
        int c = now_c + dc[i];
        if(inmap(r, c) && !vis[map[r][c] - 'A']){
            vis[map[r][c] - 'A'] = true;
            dfs(dep + 1, r, c);
            vis[map[r][c] - 'A'] = false;
        }
    }
}



int main(){
    cin >> row >> col;
    for(int i = 1; i <= row; i ++)
        for(int j = 1; j <= col; j ++)
            cin >> map[i][j];
    memset(vis, false, sizeof(vis));
    vis[map[1][1] - 'A'] = true;
    dfs(1, 1, 1);
    cout << ans << endl;
    return 0;
}
