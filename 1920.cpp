#include<bits/stdc++.h>
using namespace std;

vector<int> v;
int N, M;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    while(N--){
        int n; cin >> n;
        v.push_back(n);
    }
    sort(v.begin(), v.end());
    cin >> M;
    while(M--){
        int target; cin >> target;
        int l = 0;
        int r = v.size();
        int m;
        while(l < r){
            m = (l + r) / 2;
            if(v[m] < target){
                l = m + 1;
            } else if(v[m] > target){
                r = m;
            } else {
                cout << 1 << "\n";
                break;
            }
        }
        if(v[m] != target) cout << 0 << "\n";
    }
}