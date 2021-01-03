#include <bits/stdc++.h>
using namespace std; 
using pi = pair<int, int>;

const int MAXN = 16;
const int dy[3] = {0, 1, 1};
const int dx[3] = {1, 1, 0};
const int di[3] = {-1, 0, 1};

int home[MAXN][MAXN];
int N;

int ans = 0;

void DFS(pair<pi, int> root){
    int y = root.first.first, x = root.first.second;
    int state = root.second;
    if(y == N - 1 && x == N - 1){
        ans += 1;
        return;
    }

    for(int i = 0 ; i < 3 ; i++){
        int d = state + di[i];
        if(0 <= d && d < 3){
            int ny = y + dy[d];
            int nx = x + dx[d];
            if(0 <= ny && ny < N && 0 <= nx && nx < N){
                if(d == 1){
                    if(home[y + dy[0]][x + dx[0]] == 1) continue;
                    if(home[y + dy[2]][x + dx[2]] == 1) continue;
                }
                if(home[ny][nx] == 1) continue;
                DFS(make_pair(pi(ny, nx), d));
            }
        } 
    }
}

void init(){
    cin >> N;
    for(int i = 0 ; i < N ; i++)
        for(int j = 0 ; j < N ; j++)
            cin >> home[i][j];
}

void solve(){
    //0 가로, 1 대각, 2 세로
    DFS(make_pair(pi(0, 1), 0));
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
}