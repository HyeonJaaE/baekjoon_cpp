#include <bits/stdc++.h>
using namespace std; 
using pi = pair<int, int>;

int n;
int board[20][20];
int ans = -1;

void check(vector<int> dir, int nboard[20][20]){
    for(auto d: dir){

        switch(d){
            case 1:
                for(int j = 0 ; j < n ; j++){
                    vector<int> nums;
                    for(int i = 0 ; i < n ; i++){
                        if(nboard[i][j] != 0) nums.push_back(nboard[i][j]);
                        nboard[i][j] = 0;
                    }                    
                    int idx = 0;
                    while(idx < nums.size()){
                        if(idx + 1 < nums.size() && nums[idx] == nums[idx+1]){
                            nums[idx] *= 2;
                            nums.erase(nums.begin() + idx + 1);
                        }
                        ans = max(nums[idx], ans);
                        nboard[idx][j] = nums[idx];
                        idx += 1;
                    }
                }
                break;
            case 2:
                for(int i = 0 ; i < n ; i++){
                    vector<int> nums;
                    for(int j = 0 ; j < n ; j++){
                        if(nboard[i][j] != 0) nums.push_back(nboard[i][j]);
                        nboard[i][j] = 0;
                    }
                    reverse(nums.begin(), nums.end());
                    int idx = 0;
                    while(idx < nums.size()){
                        if(idx + 1 < nums.size() && nums[idx] == nums[idx+1]){
                            nums[idx] *= 2;
                            nums.erase(nums.begin() + idx + 1);
                        }
                        ans = max(nums[idx], ans);
                        nboard[i][n - idx - 1] = nums[idx];
                        idx += 1;
                    }
                }
                break;
            case 3:
                for(int j = 0 ; j < n ; j++){
                    vector<int> nums;
                    for(int i = 0 ; i < n ; i++){
                        if(nboard[i][j] != 0) nums.push_back(nboard[i][j]);
                        nboard[i][j] = 0;
                    }                    
                    reverse(nums.begin(), nums.end());
                    int idx = 0;
                    while(idx < nums.size()){
                        if(idx + 1 < nums.size() && nums[idx] == nums[idx+1]){
                            nums[idx] *= 2;
                            nums.erase(nums.begin() + idx + 1);
                        }
                        ans = max(nums[idx], ans);
                        nboard[n - idx - 1][j] = nums[idx];
                        idx += 1;
                    }
                }
                break;
            case 4:
                for(int i = 0 ; i < n ; i++){
                    vector<int> nums;
                    for(int j = 0 ; j < n ; j++){
                        if(nboard[i][j] != 0) nums.push_back(nboard[i][j]);
                        nboard[i][j] = 0;
                    }
                    int idx = 0;
                    while(idx < nums.size()){
                        if(idx + 1 < nums.size() && nums[idx] == nums[idx+1]){
                            nums[idx] *= 2;
                            nums.erase(nums.begin() + idx + 1);
                        }
                        ans = max(nums[idx], ans);
                        nboard[i][idx] = nums[idx];
                        idx += 1;
                    }
                }
                break;
        }
    }    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> board[i][j];
        }
    }
    for(int a = 1 ; a <= 4 ; a++){
        for(int b = 1 ; b <= 4 ; b++){
            for(int c = 1 ; c <= 4 ; c++){
                for(int d = 1 ; d <= 4 ; d++){
                    for(int e = 1 ; e <= 4 ; e++){
                        vector<int> dir = {a, b, c, d, e};
                        int nboard[20][20];
                        for(int i = 0 ; i < n ; i++){
                            for(int j = 0 ; j < n ; j++){
                                nboard[i][j] = board[i][j];
                            }
                        }
                        check(dir, nboard);
                    }
                }
            }
        }
    }
    cout << ans << "\n";
}
