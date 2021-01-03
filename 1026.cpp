#include<bits/stdc++.h>
using namespace std;

int N;
vector<int> v[2];

int ans = 0;

int main(){
    cin >> N;
    for(int i = 0 ; i < 2 ; i++){
        for(int j = 0 ; j < N ; j++){
            int n; cin >> n;
            v[i].push_back(n);
        }
    }
    sort(v[0].begin(), v[0].end());
    sort(v[1].begin(), v[1].end(), greater<int>());

    for(int i = 0 ; i < N ; i++){
        ans += v[0][i] * v[1][i];
    }
    
    cout << ans << "\n";
}