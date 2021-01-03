#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

vector<vector<pair<int, ll>>> tree;

void DFS(int D, int E, int min, int max){
    if(D == E){
        cout << min << " " << max << endl;
        return;
    }
    
    for( int i = 0; i < tree[D].size() ; i++){
        int k = tree[D][i].first;
        ll v = tree[D][i].second;
        if(visit[k] == 0){
            visit[k] = 1;
            DFS(k, E, min > v ? v : min, max < v ? v : max);
        }
    }
}


int main(){
    int N, K, A, B, C, D, E;
    cin >> N;
    tree.resize(N + 1);
    for( int i = 0 ; i < N - 1 ; i++){
        cin >> A >> B >> C;
        tree[A].push_back(make_pair(B, C));
        tree[B].push_back(make_pair(A, C));
    }
    cin >> K;
    while(K--){
        cin >> D >> E;
        visit[D] = 1;
        static int visit[100001];
        DFS(D, E, 1000000, 0);
    }
    return 0;
}