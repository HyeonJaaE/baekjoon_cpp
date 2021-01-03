#include<bits/stdc++.h>
using namespace std;

vector<int> v;
int N;

int main(){
    cin >> N;
    while(N){
        v.push_back(-(N % 10));
        N /= 10;
    }
    sort(v.begin(), v.end());
    for(int i = 0 ; i < v.size() ; i++){
        N += -v[i];
        N *= 10;
    }
    cout << N / 10 << "\n";
}