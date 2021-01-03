#include <bits/stdc++.h>
using namespace std;

const int MAXN = 101;

int li[MAXN][MAXN] = {0, };
int visit[MAXN];

void DFS(int n){
    cout << n;
    for(int i = 0; i < MAXN; i++){
        if(li[n][i] == 1 && visit[i] == 0){
            visit[i] = 1;
            DFS(i);
        }
    }
} 

int main(){
    int N; cin >> N;
    int E; cin >> E;
    
    for(int i = 0 ; i < E; i++){
        int n1, n2;
        cin >> n1 >> n2;
        li[n1][n2] = 1;
        li[n2][n1] = 1;
    }
    
    for(int i = 1; i < N + 1 ; i++){
        if(visit[i] == 0){
            visit[i] = 1;
            DFS(i);
        }
    }
}