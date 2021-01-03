#include <bits/stdc++.h>
using namespace std; 
using pi = pair<int, int>;

const int INF = 1234567890;
const int MAXN = 100001;

vector<pi> seg;
int nums[MAXN];
int N, M;

pi getTree(int l, int r, int pos, int targetL, int targetR){
    if(r < targetL || l > targetR) return pi(INF, 0);
    if(targetL <= l && r <= targetR) return seg[pos];
    int mid = (l + r) / 2;
    pi leftSeg = getTree(l, mid, pos * 2, targetL, targetR);
    pi rightSeg = getTree(mid + 1, r, pos * 2 + 1, targetL, targetR);
    return pi(min(leftSeg.first, rightSeg.first),
            max(leftSeg.second, rightSeg.second));
}

pi setTree(int l, int r, int pos){
    int mid = (l + r) / 2;
    if(l == r){
        return seg[pos] = pi(nums[l], nums[l]);
    } else {
        pi leftSeg = setTree(l, mid, 2 * pos);
        pi rightSeg = setTree(mid + 1, r, 2 * pos + 1);
        return seg[pos] = pi(min(leftSeg.first, rightSeg.first),
                            max(leftSeg.second, rightSeg.second));
    }
}

void init(){
    cin >> N >> M;
    seg.resize(N * 4);
    for(int i = 1 ; i <= N ; i++)
        cin >> nums[i];
    setTree(1, N, 1);
}

void solve(){
    for(int i = 0 ; i < M ; i++){
        int a, b;
        cin >> a >> b;
        pi ans = getTree(1, N, 1, a, b);
        cout << ans.first << " " << ans.second << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
}