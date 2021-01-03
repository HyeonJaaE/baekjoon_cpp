#include <bits/stdc++.h>
using namespace std; 
using pi = pair<int, int>;

const int MAXN = 11;
const int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};

vector<int> trees[MAXN][MAXN];
int energy[MAXN][MAXN];
int refill[MAXN][MAXN];
int N, M, K;
int ans = 0;

void init(){
    cin >> N >> M >> K;
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= N ; j++){
            cin >> refill[i][j];
            energy[i][j] = 5;
        }
    }
    for(int i = 0 ; i < M ; i++){
        int y, x, z;
        cin >> y >> x >> z;
        trees[y][x].push_back(z);
    }
}

void solve(){
    while(K--){
        vector<int> ntrees[MAXN][MAXN];
        for(int i = 1 ; i <= N ; i++){
            for(int j = 1 ; j <= N ; j++){
                //spring
                sort(trees[i][j].begin(), trees[i][j].end());
                for(int t = 0 ; t < trees[i][j].size() ; t++){
                    int &tree = trees[i][j][t];
                    if(energy[i][j] >= tree){
                        energy[i][j] -= tree;
                        tree += 1;
                    } else {
                        tree = -tree;
                    }
                }

                //summer
                while(trees[i][j].size() > 0){
                    int tree = trees[i][j].back();
                    if(tree < 0){
                        tree = -tree;
                        energy[i][j] += tree / 2;
                        trees[i][j].pop_back();
                    } else {
                        break;
                    }
                }

                //fall
                for(auto tree: trees[i][j]){
                    if(tree % 5 == 0){
                        for(int d = 0 ; d < 8 ; d++){
                            int ny = i + dy[d], nx = j + dx[d];
                            if(0 < ny && ny <= N && 0 < nx && nx <= N)
                                ntrees[ny][nx].push_back(1);
                        }
                    }
                }
            }
        }
        for(int i = 1 ; i <= N ; i++){
            for(int j = 1 ; j <= N ; j++){
                //fall2
                trees[i][j].insert(trees[i][j].end(), ntrees[i][j].begin(), ntrees[i][j].end());
                //winter
                energy[i][j] += refill[i][j];
            }
        }
    }
    
    for(int i = 1 ; i <= N ; i++)
        for(int j = 1 ; j <= N ; j++)
            ans += trees[i][j].size();
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
}