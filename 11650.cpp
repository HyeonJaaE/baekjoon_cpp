#include<bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;

vector<pi> v;
int N;

int main(){
    cin >> N;
    while(N--){
        int x, y; cin >> x >> y;
        v.push_back(pi(x,y));
    }
    sort(v.begin(), v.end());
    for(auto _v: v) cout << _v.first << " " << _v.second << "\n";
}