#include <bits/stdc++.h>
using namespace std; 
using pi = pair<int, int>;

vector<int> v;
int N;

void init(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    while(N--){
        int n; cin >> n;
        v.push_back(n);
    }
}


void solve(){
    sort(v.begin(), v.end());
    for(auto _v: v) cout << _v << "\n";
}

int main(){
    init();
    solve();
}