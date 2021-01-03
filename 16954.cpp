#include <bits/stdc++.h>
using namespace std;

int len = 0;
vector<int> ans;
vector<vector<int>> _board;

void DFS(int root, int depth, vector<int> Visit, int sum){
    if(depth == len){
        ans.push_back(sum);
        return;
    }
    for(int i = 0 ; i < len ; i++){
        if(Visit[i] == 0){
            vector<int> nVisit(Visit);
            nVisit[i] = 1;
            DFS(i, depth + 1, nVisit, sum + _board[i][depth + 1]);
        }
    }
}

int solution(vector<vector<int>> board) {
    len = board[0].size();
    _board = board;
    for(int i = 0 ; i < len ; i++){
        vector<int> Visit(len, 0);
        Visit[i] = 1;
        DFS(i, 0, Visit, board[i][0]);
    }
    for(auto foo: ans){
        cout << foo << " " ;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solution({{12,15},{19,21}});
        
}