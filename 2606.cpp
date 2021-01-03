#include <bits/stdc++.h>
using namespace std; 
using pi = pair<int, int>;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);   

    vector<vector<int>> nodes(101);
    int visit[101] = {0, };

    int N; cin >> N;
    int E; cin >> E;
    for(int i = 0 ; i < E ;i ++){
        int e1, e2; cin >> e1 >> e2;
        nodes[e1].push_back(e2);
        nodes[e2].push_back(e1);
    }

    deque<int> dq = {1};
    visit[1] = 1;
    int cnt = 0;
    while(dq.size() > 0){
        int n = dq.front();
        dq.pop_front();
        //cout << "n : " << n << endl;
        for(auto p: nodes[n]){
            //cout << "p : " << p << " visit : " << visit[p] << endl;
            if(visit[p] == 0){
                cnt += 1;
                visit[p] = 1;
                dq.push_back(p);
            }
        }
    }
    cout << cnt << "\n";
}