#include <bits/stdc++.h>
using namespace std;

int main(){
	int Q; cin >> Q;
    while(Q--){
        int a, b, c; cin >> a >> b >> c;
        vector<int> dies(c);
        vector<int> players(a, 1);
        vector<int> ladders(100, 0);
        for(int i = 0; i < b; i++){
            int bottom, top; cin >> bottom >> top;
            ladders[bottom] = top - bottom;
        }
        for(int i = 0; i < c; i++){
            int die; cin >> die;
            dies[i] = die;
        }
        for(int i = 0; i < c; i++){
            int p = i % a;
            players[p] += dies[i];
            players[p] += ladders[players[p]];
            if(players[p] >= 100){
                players[p] = 100;
                break;   
            }
        }
        for(int i = 0; i < a; i++){
            cout << "Position of player " << i+1 << " is " << players[i] << ".\n";        
        }
        
    }
    
}
