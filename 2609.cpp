#include<bits/stdc++.h>
using namespace std;

int gcd = 1;
int lcm = 1;

int getGCD(int a, int b){
    int h = min(a, b);
    for(int i = 1 ; i <= h ; i++){
        if(a % i == 0 && b % i == 0) gcd = i;
    }
    return gcd;
}

int getLCM(int a, int b){
    lcm = a * b / gcd;
    return lcm;
}

int main(){
    int a, b; cin >> a >> b;
    cout << getGCD(a,b) << "\n" << getLCM(a,b) << "\n";
    return 0;
}