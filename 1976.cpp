#include <bits/stdc++.h>
using namespace std; 
using pi = pair<int, int>;

const int MAXC = 200;
int cnt = 0;
int edges[MAXC][MAXC];
int v[MAXC];
int N;

void DFS(int root){
    for(int i = 0 ; i < N ; i++){
        if(edges[root][i] == 1 && v[i] == 0){
            v[i] = cnt;
            DFS(i);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n; cin >> n; N = n;
    int m; cin >> m;


    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> edges[i][j];
        }    
    }
    vector<int> plan;
    for(int i = 0 ; i < m ; i++){
        int p; cin >> p;
        plan.push_back(p);
    }
    
    for(int i = 0 ; i < n ; i++){
        if(v[i] == 0){
            cnt += 1;
            v[i] = cnt;
            DFS(i);
        }
    }
    
    int group = v[plan[0] - 1];
    for(auto p: plan){
        if(v[p-1] != group){
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
}