#include <bits/stdc++.h>
using namespace std; 
using pi = pair<int, int>;

const int MAXR = 101;
int board[MAXR][MAXR];
int N;

int ans = 0;
const int dy[4] = {0, -1, 0, 1};
const int dx[4] = {1, 0, -1, 0};

pi curve(pi loc, pi base){
    int y = loc.first, x = loc.second;
    int by = base.first, bx = base.second;
    if(y == by){
        if(x > bx) return pi(by + abs(bx - x), bx);
        if(x < bx) return pi(by - abs(bx - x), bx);
    }
    
    if(x == bx){
        if(y > by) return pi(by, bx - abs(by - y));
        if(y < by) return pi(by, bx + abs(by - y));
    }

    if(x > bx && y < by) return pi(by + abs(x - bx), bx + abs(y - by)); 
    if(x > bx && y > by) return pi(by + abs(x - bx), bx - abs(y - by));
    if(x < bx && y < by) return pi(by - abs(x - bx), bx + abs(y - by));
    if(x < bx && y > by) return pi(by - abs(x - bx), bx - abs(y - by));
}

void init(){
    cin >> N;
}

void solve(){
    for(int i = 0 ; i < N ; i++){
        //d : 0, 1, 2, 3 <-> 우, 상, 좌, 하
        int x, y, d, g;
        cin >> x >> y >> d >> g;
        pi base = pi(y + dy[d], x + dx[d]);
        board[y][x] = i + 1;
        board[base.first][base.second] = i + 1;
        vector<pi> coor = {pi(y,x), base};
        while(g--){
            int csize = coor.size();
            for(int j = 1 ; j < csize ; j++){
                if(coor[j] == base) continue;
                //cout << coor[i].first << " , " << coor[i].second << " => ";
                pi res = curve(coor[j], base);
                //cout << res.first << " , " << res.second << "\n";
                coor.push_back(res);
                board[res.first][res.second] = i + 1;
            }
            //base
            base = curve(coor[0], base);
            //cout << "base " << base.first << " , " << base.second << "\n";
            coor.push_back(base);
            board[base.first][base.second] = i + 1;
        }
    }
    for(int i = 0 ; i < MAXR ; i++){
        for(int j = 0 ; j < MAXR ; j++){
            if(board[i][j] == 0) continue;
            if(i + 1 > 100 || board[i+1][j] == 0) continue;
            if(j + 1 > 100 || board[i][j+1] == 0) continue;
            if(board[i+1][j+1] == 0) continue;
            ans += 1;
        }
    }
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
}