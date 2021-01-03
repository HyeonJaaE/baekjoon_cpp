#include <bits/stdc++.h>
using namespace std; 
using pi = pair<int, int>;

const int INF = 987654321;
const int MAXN = 500001;
int ans[MAXN];
int N;
stack<pi> s;

void init(){
    cin >> N;
    s.push(pi(INF, 0));
}

void solve(){
    for(int i = 1 ; i <= N ; i++){
        int tower; cin >> tower;
        while(s.top().first <= tower){
            s.pop();
        }
        ans[i] = s.top().second;
        s.push(pi(tower,i));
    }
    
    for(int i = 1 ; i <= N ; i++){
        cout << ans[i] << " ";
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
}