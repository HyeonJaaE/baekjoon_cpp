#include<bits/stdc++.h>
using namespace std;

vector<int> v;
vector<int> p;
int N, M;

void getNum(vector<int> &path){
    if(path.size() == M){
        for(auto p: path){
            cout << p << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = 1 ; i <= N ; i++){
        if(find(path.begin(), path.end(), i) == path.end()){
            path.push_back(i);
            getNum(path);
            path.pop_back();
        };
    }    
}

int main(){
    cin >> N >> M;
    getNum(p);
}