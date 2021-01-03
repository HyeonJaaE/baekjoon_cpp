#include <bits/stdc++.h>
using namespace std; 
using pi = pair<int, int>;

int parent[1001];
priority_queue<pair<int, pi>> pq;
int N, M;
int ans = 0;

int getParent(int node){
    if(parent[node] == node){
        return node;
    } else {
        return getParent(parent[node]);
    }
}

int BFS(){
    while(!pq.empty()){
        int weight = pq.top().first;
        int a = getParent(pq.top().second.first);
        int b = getParent(pq.top().second.second);
        pq.pop();
        if(a != b){
            ans += -weight;
            parent[a] = min(a, b);
            parent[b] = min(a, b);
        }
    }
    return ans;
}

void init(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for(int i = 0 ; i < 1001 ; i++){
        parent[i] = i;
    }
}

void solve(){
    while(M--){
        int a, b, c; 
        cin >> a >> b >> c;
        if(a != b){
            pq.push(make_pair(-c, pi(a, b)));
        }
    }

    cout << BFS() << "\n";
}

int main(){
    init();
    solve();
}