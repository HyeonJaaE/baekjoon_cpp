#include<bits/stdc++.h>
using namespace std;

vector<int> v(10001, 0);
int N;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    while(N--){
        int n; cin >> n;
        v[n] += 1;
    }
    for(int i = 1 ; i < v.size() ; i++){
        while(v[i]--){
            cout << i << "\n";
        }
    }
}