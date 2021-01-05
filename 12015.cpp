#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1000000;

vector<int> lis;
int arr[MAXN];
int N;

void init(){
    cin >> N;
    for(int i = 0 ; i < N ; i++)
        cin >> arr[i];
}

void solve(){
    for(int i = 0 ; i < N ; i++){
        if(lis.empty() || lis.back() < arr[i] ){
            lis.push_back(arr[i]);
        } else {
            auto iter = lower_bound(lis.begin(), lis.end(), arr[i]);
            *iter = arr[i];
        }
    }
    cout << lis.size() << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
}