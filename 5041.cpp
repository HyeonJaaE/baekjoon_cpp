#define FOR(i, n) for(int i = 0 ; i < n ; i++)
#include <bits/stdc++.h>
using namespace std; 
using pi = pair<int, int>;

int visited[1000001];
int dp[1000001];
int F, S, G, U, D;


void BFS(){
    const int move[2] = {U, -D};
    visited[S] = 0;
    queue<int> q;
    q.push(S);
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int i = 0 ; i < 2 ; i++){
            int nloc = cur + move[i];
            if(1 <= nloc && nloc <= F && visited[nloc] == -1){
                q.push(nloc);
                visited[nloc] = visited[cur] + 1;
            }
        }
    }
}
void init(){
    cin >> F >> S >> G >> U >> D;
    for(int i = 0 ; i <= F ; i++) visited[i] = -1;
}

void solve(){
    BFS();
    if(visited[G] == -1){
        cout << "use the stairs\n";
    } else {
        cout << visited[G] << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
}