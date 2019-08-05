#include <bits/stdc++.h>
using namespace std;

int main(){
    int T, s, a, f;
    cin >> T;
    
    pair<int,int> min;
    
    while(T--){
        cin >> s >> a >> f;
        vector<int> xs;
        vector<int> ys;
        for(int i = 0; i < f; i++){
            int x, y;
            cin >> x >> y;
            xs.push_back(x);
            ys.push_back(y);
        }
        sort(xs.begin(),xs.end());
        sort(ys.begin(),ys.end());
        
        cout << "(Street: " << xs[(f-1)/2] << ", Avenue: " << ys[(f-1)/2] << ")\n";
    }
    cout << "\n";
    
}
