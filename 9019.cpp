#include <bits/stdc++.h>
using namespace std; 

const string DSLR = "DSLR";

vector<int> visited[10000];
int T, A, B;

void check(int res, queue<int> &q, int n, int op){
    if(visited[res].size() == 0){
        visited[res] = visited[n];
        visited[res].push_back(op);
        q.push(res);
    }
}

void BFS(){
    queue<int> q;
    q.push(A);
    while(!q.empty()){
        int n = q.front(); q.pop();

        //D
        int res = 2 * n % 10000;
        check(res, q, n, 0);

        //S
        res = n - 1;
        if(res < 0) res = 9999;
        check(res, q, n, 1);

        int d1 = n / 1000;
        int d2 = n % 1000 / 100;
        int d3 = n % 100 / 10;
        int d4 = n % 10;

        //L abcd => bcda
        res = d1 + d4 * 10 + d3 * 100 + d2 * 1000;
        check(res, q, n, 2);

        //R abcd => dabc
        res = d3 + d2 * 10 + d1 * 100 + d4 * 1000;
        check(res, q, n, 3);
    }
}

void init(){
    for(int i = 0 ; i < 10000 ; i++) visited[i].clear();
    cin >> A >> B;
    visited[A].push_back(-1);
}

void solve(){
    BFS();
    for(int i = 1 ; i < visited[B].size(); i++)
        cout << DSLR[visited[B][i]];   
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while(T--){
        init();
        solve();
    }
}