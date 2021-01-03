#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100001;

int visited[MAXN];
int student[MAXN];
int T, N;
int gcnt;
int ans;

void DFS(int node, vector<int> &path){
    path.push_back(student[node]);
    if(!visited[student[node]]){
        visited[student[node]] = 1;
        DFS(student[node], path);
    } else {
        for(int i = 0 ; i < path.size() ; i++){
            cout << "path" << path[i] << "\n";
            if(path[i] == student[node]) break;
            ans += 1;
        }
    }
}

void init(){
    cin >> N;
    memset(student, 0, sizeof(student));
    memset(visited, 0, sizeof(visited));
    ans = 0;
    for(int i = 1 ; i <= N ; i++)
        cin >> student[i];
}

void solve(){
    for(int i = 1 ; i <= N ; i++){
        if(!visited[i]){
            visited[i] = 1;
            vector<int> path = {i};
            DFS(i, path);
        }
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while(T--){
        init();
        solve();
    }
    return 0;
}