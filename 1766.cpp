#include <bits/stdc++.h>
using namespace std; 
using pi = pair<int, int>;

const int MAXN = 32001;

vector<int> order[MAXN];
vector<int> ans;
int visited[MAXN];
int deg[MAXN];
int N, M;

void init(){
    cin >> N >> M;
    for(int i = 0 ; i < M ; i++){
        int A, B;
        cin >> A >> B;
        deg[B] += 1;
        order[A].push_back(B);
    }
}

void solve(){
    while(ans.size() < N){
        for(int i = 1 ; i <= N ; i++){
            if(deg[i] == 0 && visited[i] == 0){
                visited[i] = 1;
                ans.push_back(i);
                for(auto d: order[i]){
                    deg[d] -= 1;
                }
                break;
            }
        }
    }
    for(auto a: ans) cout << a << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
}