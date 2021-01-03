#include <bits/stdc++.h>
using namespace std; 
using pi = pair<int, int>;

int N;
int RGB[1000][3];

void init(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for(int i = 0 ; i < N ;i++){
        cin >> RGB[i][0] >> RGB[i][1] >> RGB[i][2];
    }
}

void solve(){
    for(int i = 1 ; i < N ; i++){
        RGB[i][0] += min(RGB[i-1][1], RGB[i-1][2]);
        RGB[i][1] += min(RGB[i-1][0], RGB[i-1][2]);
        RGB[i][2] += min(RGB[i-1][0], RGB[i-1][1]);
    }
    cout << min({RGB[N-1][0], RGB[N-1][1], RGB[N-1][2]}) << "\n";
}

int main(){
    init();
    solve();
}