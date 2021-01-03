#include <bits/stdc++.h>
#include <vector>
using namespace std; 
using pi = pair<int, int>;


int board[51][51];
int nboard[51][51];
int N, M, K;
int ans = 987654321;

void get_m_value(){
    for(int i = 1 ; i <= N ; i++){
        int sum = 0;
        for(int j = 1 ; j <= M ; j++){
            sum += nboard[i][j];
        }
        ans = min(ans, sum);
    }
}

void Rotate(vector<int> op){
    int r = op[0], c = op[1], s = op[2];
    int d = 0, S = s;
    while(S--){
        int i = r - s + d;
        int j = c - s + d;
        int tmp = nboard[i][j];
        
        while(++i <= r + s - d){
            nboard[i-1][j] = nboard[i][j];
        }
        i -= 1;

        while(++j <= c + s - d){
            nboard[i][j-1] = nboard[i][j];
        }
        j -= 1;

        while(--i >= r - s + d){
            nboard[i+1][j] = nboard[i][j];
        }
        i += 1;

        while(--j > c - s + d){
            nboard[i][j+1] = nboard[i][j];
        }
        
        nboard[i][j+1] = tmp;
        d += 1;
    }
}

int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);

    cin >> N >> M >> K;
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1; j <= M ; j++){
            cin >> board[i][j];
        }
    }

    vector<vector<int>> op;
    while(K--){
        int r, c, s; cin >> r >> c >> s;
        op.push_back({r,c,s});
    }

    vector<int> orders;
    for(int i = 0 ; i < op.size() ; i++){
        orders.push_back(i);
    }

    do {
        for(int i = 1 ; i <= N ; i++){
            for(int j = 1 ; j <= M ; j++){
                nboard[i][j] = board[i][j];
            }
        }
        for(auto order: orders){
            Rotate(op[order]);
        }
        get_m_value();
    } while(next_permutation(orders.begin(), orders.end()));

    cout << ans << "\n";
}
