#include <bits/stdc++.h>
using namespace std; 
using pi = pair<int, int>;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> v;
    int N; cin >> N;
    for(int i = 0 ; i < N ; i++){
        int num; cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    int ans = 0;
    for(int i = 0 ; i < N ; i++){
        ans += v[i] + v[i] * (N - i - 1);
    }
    cout << ans << "\n";
}

