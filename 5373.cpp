#include <bits/stdc++.h>
using namespace std;

int T, N;

void rotate_r(vector<int> target, vector<vector<vector<int>>> &cube){
    vector<vector<int>> ncube(3);
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 2 ; j >= 0 ; j--){
            ncube[i].push_back(cube[target[0]][j][i]);
        }
    }
    cube[target[0]] = ncube;
    
    vector<int> tmp(cube[target[1]][0]);
    cube[target[1]][0] = cube[target[2]][0];
    cube[target[2]][0] = cube[target[3]][0];
    cube[target[3]][0] = cube[target[4]][0];
    cube[target[4]][0] = tmp;
}

void rotate_l(vector<int> target, vector<vector<vector<int>>> &cube){
    vector<vector<int>> ncube(3);
    for(int i = 2 ; i >= 0 ; i--){
        for(int j = 0 ; j < 3 ; j++){
            ncube[2-i].push_back(cube[target[0]][j][i]);
        }
    }
    cube[target[0]] = ncube;
    
    vector<int> tmp(cube[target[1]][0]);
    cube[target[1]][0] = cube[target[4]][0];
    cube[target[4]][0] = cube[target[3]][0];
    cube[target[3]][0] = cube[target[2]][0];
    cube[target[2]][0] = tmp;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> T;
    while(T--){
        //up down front back left right
        //white, yellow, red, orange, green, blue
        vector<vector<vector<int>>> cube(6, vector<vector<int>>(3, vector<int>(3)));
        for(int i = 0 ; i < 6 ; i++){
            for(int j = 0 ; j < 3 ; j++){
                for(int k = 0 ; k < 3 ; k++){
                    cube[i][j][k] = i;
                }
            }
        }

        cin >> N;
        for(int i = 0 ; i < N ; i++){
            string op; cin >> op;
            vector<int> target;

            switch(op[0]){
                case 'U':
                    target = {0,2,5,3,4};
                    break;
                case 'D':
                    target = {1,2,5,3,4};
                    break;
                case 'F':
                    target = {2,0,4,1,5};
                    break;
                case 'B':
                    target = {3,0,4,1,5};
                    break;
                case 'L':
                    target = {4,0,2,1,3};
                    break;
                case 'R':
                    target = {5,0,2,1,3};
                    break;
            }

            switch(op[1]){
                case '+':
                    rotate_r(target, cube);
                case '-':
                    rotate_l(target, cube);
            }
        }
        
        for(int r = 0 ; r < 3 ; r++){
            for(int c = 0 ; c < 3 ; c++){
                cout << cube[0][r][c];
            }
            cout << "\n";
        }
    }
}