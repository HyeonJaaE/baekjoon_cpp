#include<bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;

const int INF = 987654321;
int ladder[31][10];
int N, M, H;
int ans = INF;

bool check(){
    for(int i = 0 ; i < N ; i++){
        pi pos = pi(0, i);
        while(true){
            int &ny = pos.first;
            int &nx = pos.second;
            ny += 1;
            nx += ladder[ny][nx];
            if(ny == H){
               if(nx != i) return false;
               break;
            }
        }
    }
    return true;
}

void DFS(int y, int x, int cnt){
    if(cnt > ans || cnt > 3) return;
    ladder[y][x] = 1;
    ladder[y][x+1] = -1;
    if(check()){
        ans = min(ans, cnt);
    } else{
        for(int j = x ; j < N - 1 ; j++)
            if(ladder[y][j] == 0 && ladder[y][j+1] == 0) DFS(y, j, cnt + 1);

        for(int i = y + 1 ; i <= H ; i++)
            for(int j = 0 ; j < N - 1 ; j++)
                if(ladder[i][j] == 0 && ladder[i][j+1] == 0) DFS(i, j, cnt + 1);
    }
    ladder[y][x] = 0;
    ladder[y][x+1] = 0;
}

void init(){
    cin >> N >> M >> H;
    for(int i = 0 ; i < M ; i++){
        int a, b;
        cin >> a >> b;
        ladder[a][b-1] = 1;
        ladder[a][b] = -1;
    }    
}

void solve(){
    if(check()){
        cout << 0 << "\n";
        return;
    }

    for(int i = 1 ; i <= H ; i++){
        for(int j = 0 ; j < N - 1; j++){
            if(ladder[i][j] == 0 && ladder[i][j+1] == 0) DFS(i, j, 1);
        }
    }

    if(ans == INF){
        cout << -1 << "\n";
    } else {
        cout << ans << "\n";
    }
}

int main(){
    /* ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0); */
    init();
    solve();
}