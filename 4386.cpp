#include <bits/stdc++.h>
using namespace std; 
using pd = pair<double, double>;
using pi = pair<int, int>;

vector<pd> stars;
vector<pair<pi, double>> edges;
vector<int> parent;

int get_parent(int num){
    while(num != parent[num]){
        num = parent[num];
    }
    return num;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n; cin >> n;
    while(n--){
        double x, y; cin >> x >> y;
        stars.push_back(pd(x,y));
    }

    for(int i = 0; i < stars.size(); i++){
        parent.push_back(i);
        for(int j = 0 ; j < stars.size(); j++){
            if( i == j ) continue;
                double dx = stars[i].first - stars[j].first;
                double dy = stars[i].second - stars[j].second;
                double dis = sqrt(pow(dx, 2) + 
                pow(dy, 2));
                edges.push_back(make_pair(pi(i, j), dis));
        }
    }
    
    sort(edges.begin(), edges.end(),
        [](pair<pi,double> a, pair<pi, double> b) -> bool {
            return a.second < b.second;    
        } );
        
    /*
    for(auto foo: edges){
        cout << foo.first.first <<" "<< foo.first.second << " "<< foo.second << "\n";
    }
    */

    double sum = 0;
    for(auto edge: edges){
        /*
        cout << "parent vector :";
        for(auto p: parent){
            cout << p << " ";
        }
        cout << "\n";
        */
        int from = edge.first.first;
        int to = edge.first.second;
        double dis = edge.second;
        
        int p1 = get_parent(from);
        int p2 = get_parent(to);
        if(p1 != p2){
            parent[p1] = min(p1, p2);
            parent[p2] = min(p1, p2);
            sum += dis;
        }
    }
    cout << setprecision(3) << sum;
}