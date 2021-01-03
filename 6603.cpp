#include<bits/stdc++.h>
using namespace std;

vector<int> v;

void DFS(int root, vector<int> &path){
    if(path.size() == 6){
        for(auto p: path) cout << p << " ";
        cout << "\n";
        return;
    }
    for(int i = root ; i < v.size(); i++){
        path.push_back(v[i]);q
        DFS(i + 1, path);
        path.pop_back();
    }
}

int main(){
    while(true){
        int K; cin >> K;
        if(!K) break;
        v.resize(K);
        for(int i = 0 ; i < K ; i++)
            cin >> v[i];
        vector<int> path;
        DFS(0, path);
        cout << "\n";
    }
}