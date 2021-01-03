#include <bits/stdc++.h>
using namespace std; 

const int MAXN = 10001;

int weights[MAXN];
int dp[MAXN][2];
int visited[MAXN];
vector<vector<int>> edges;
vector<int> ans;

void tracking(int select, int root){
    visited[root] = 1;
    // select = 0 부모 노드 출력 안했음
    if(dp[root][1] > dp[root][0] && !select){
        ans.push_back(root);
        select = 1;
    } else {
        select = 0;
    }
    
    for(auto child: edges[root]){
        if(visited[child] == 0){
            tracking(select, child);
        }
    }
}

void DFS(int parent, int root){
    visited[root] = 1;
    dp[root][1] = weights[root];
    for(auto child: edges[root]){
        if(visited[child] == 0){
            DFS(root, child);
        }
    }

    //dp[n][0] : n 을 포함하지 않는 경우
    //dp[n][1] : n 을 포함하는 경우
    for(auto child: edges[root]){
        if(child == parent) continue;
        dp[root][0] += max(dp[child][1], dp[child][0]);
        dp[root][1] += dp[child][0];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> weights[i];
    }

    edges = vector<vector<int>>(n + 1);
    for(int i = 0 ; i < n - 1 ; i++){
        int e1, e2; cin >> e1 >> e2;
        edges[e1].push_back(e2);
        edges[e2].push_back(e1);
    }
    
    DFS(1,1);
    memset(visited, 0, sizeof(visited));
    tracking(0, 1);
    sort(ans.begin(), ans.end());
    cout << max(dp[1][0], dp[1][1]) << "\n";
    for(auto a: ans){
        cout << a << " " ;
    }
    cout << "\n";
}