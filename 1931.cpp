#include<bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;

vector<pair<int, pi>> confTime;
int N, ans;

void init(){
    cin >> N;
    for(int i = 0 ; i < N ; i++){
        int s, e; cin >> s >> e;
        confTime.push_back(make_pair(e-s, pi(s,e)));
    }
    sort(confTime.begin(), confTime.end());
}

void solve(){
    for(int i = 0 ; i < confTime.size() ; i++){
        cout << confTime[i].first << " , " << confTime[i].second.first << " , " << confTime[i].second.second << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();   
}