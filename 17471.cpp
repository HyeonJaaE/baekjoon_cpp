#include <bits/stdc++.h>
using namespace std; 
#define INF 987654321

const int MAXC = 10;
int ans = INF;
vector<int> p(MAXC);
vector<vector<int>> board(MAXC);
int Visit[MAXC];
int group[MAXC];
int gp[2];
int N, check;


void DFS(int root, int gn){
    for(auto nroot: board[root]){
        if(Visit[nroot] == 0 && group[nroot] == gn){
            check += 1;
            Visit[nroot] = 1;
            gp[gn] += p[nroot];
            DFS(nroot, gn);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> N;
    for(int i = 0 ; i < N ; i++){
        cin >> p[i];
    }

    for(int i = 0 ; i < N ; i++){
        int c; cin >> c;
        while(c--){
            int num; cin >> num;
            board[i].push_back(num - 1);
        }
    }

    for(int i = 1 ; i < (1 << N) ; i++){
        memset(group, 0, sizeof(group));
        memset(Visit, 0, sizeof(Visit));
        memset(gp, 0, sizeof(gp));
        check = 0;

        //set group 0 or 1
        for(int j = 0 ; j < 10 ; j++){
            if(i & (1 << j)){
                group[j] = 1;
            }
        }

        //check must return N
        for(int j = 0 ; j < N ; j++){
            if(Visit[j] == 0 && group[j] == 0){
                gp[0] += p[j];
                Visit[j] = 1;
                check += 1;
                DFS(j, 0);
                break;
            }
        }

        for(int j = 0 ; j < N ; j++){
            if(Visit[j] == 0 && group[j] == 1){
                gp[1] += p[j];
                Visit[j] = 1;
                check += 1;
                DFS(j, 1);
                break;
            }
        }

        if(check == N){
            ans = min(ans, abs(gp[0] - gp[1]));
        }
    }

    if(ans == INF) cout << -1 << "\n";
    else cout << ans << "\n";
}