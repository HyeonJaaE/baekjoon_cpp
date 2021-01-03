#include<bits/stdc++.h>
using namespace std;

vector<int> v;
int N, K;

int main(){
    cin >> N >> K;
    int idx = 0;
    for(int i = 0 ; i < N ; i++){
        v.push_back(i+1);
    }

    cout << "<";
    while(v.size() > 1){
        idx = (idx + K - 1) % v.size();
        cout << v[idx] << ", ";
        v.erase(v.begin() + idx);
    }
    cout << v[0] << ">\n";
}