#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int INF = 987654321;
int board[3];
int maxdp[2][3];
int mindp[2][3];
int N;

int main(){
    cin >> N;

    for(int i = 0 ; i < N ; i++){
        cin >> board[0] >> board[1] >> board[2];
        for(int j = 0 ; j < 3 ; j++)
            mindp[1][j] = INF;
        for(int j = 0 ; j < 3 ; j++){
            for(int d = -1 ; d < 2 ; d++){
                int idx = j + d;
                if(0 <= idx && idx < 3){
                    maxdp[1][j] = max(maxdp[1][j], board[j] + maxdp[0][idx]);
                    mindp[1][j] = min(mindp[1][j], board[j] + mindp[0][idx]);
                }
            }
        }
        for(int j = 0 ; j < 3 ; j++){
            maxdp[0][j] = maxdp[1][j];
            mindp[0][j] = mindp[1][j];
        }
    }

    cout << max({maxdp[0][0], maxdp[0][1], maxdp[0][2]}) << " ";
    cout << min({mindp[0][0], mindp[0][1], mindp[0][2]}) << "\n";
}