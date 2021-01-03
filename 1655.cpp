#include <bits/stdc++.h>
using namespace std; 
using pi = pair<int, int>;

vector<int> nums;
int insertN(int n){
    int len = nums.size();
    if(len == 0) nums.push_back(n);
    else{
        int l = 0;
        int r = len;
        while(l < r){
            int mid = (l + r) / 2;
            if(n >= nums[mid]){
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        nums.insert(nums.begin() + r, n);
    }

    len += 1;
    if(len % 2 == 0){
        return (nums[len/2] > nums[len/2 - 1]) ? nums[len/2 - 1] : nums[len/2];
    } else {
        return nums[len/2];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    for(int i = 0 ; i < N ; i++) {
        int n; cin >> n;
        cout << insertN(n) << "\n";
    }
}