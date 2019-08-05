#include <bits/stdc++.h>
using namespace std;

int v[9][9] = {
-1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, 1, 2, 3, -1, -1, -1,
-1, -1, -1, 4, 5, 6, -1, -1, -1,
-1, 7, 8, 9, 10, 11, 12, 13, -1, 
-1, 14, 15, 16, 17, 18, 19, 20, -1,
-1, 21, 22, 23, 24, 25, 26, 27, -1,
-1, -1, -1, 28, 29, 30, -1, -1, -1,
-1, -1, -1, 31, 32, 33, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1
};

int pos[33]={
        12, 13, 14,
        21, 22, 23, 
28, 29, 30, 31, 32, 33, 34, 
37, 38, 39, 40, 41, 42, 43, 
46, 47, 48, 49, 50, 51, 52, 
        57, 58, 59, 
        66, 67, 68
};

vector<pair<pair<int,int>,pair<int,int>>> moves;
set <pair<int,int>> pegs;

bool compare(pair<pair<int, int>,pair<int,int>> p1, pair<pair<int, int>,pair<int,int>> p2) { 
    if(p1.first < p2.first) {
        return true;
    } else if (p1.first == p2.first){
        return (p1.second <= p2.second);
    } else {
        return false;
    }
} 

bool is_valid(int i, int j){
    if(i == 8 || i == 0 || j == 8 || j == 0) return false;
    if(i <= 2|| i >= 6){
        if(j <= 2 || j >= 6) return false;
    }
    return true;
}

pair<pair<int,int>,pair<int,int>> best_move(){
    sort(moves.begin(), moves.end(), compare);
    return moves[moves.size() - 1];
}

void move(pair<int,int> m, pair<int,int> ch){
    auto it1 = pegs.find(ch);
    pegs.erase(it1);
    auto it2 = pegs.find({(ch.first + m.first)/2, (ch.second + m.second)/2});
    pegs.erase(it2);
    pegs.insert(m);
}  

void calc_moves(){
    moves.erase(moves.begin(), moves.end());
    for(auto e: pegs){
        int i = e.first;
        int j = e.second;
        if(pegs.find({i + 1, j}) != pegs.end()){
            if(pegs.find({i + 2, j}) == pegs.end() && 
            is_valid(i + 2, j)){
                moves.push_back({{i + 2, j}, {i, j}});
            }
        }
        if(pegs.find({i - 1, j}) != pegs.end()){
            if(pegs.find({i - 2, j}) == pegs.end() && 
            is_valid(i - 2, j)){
                moves.push_back({{i - 2, j}, {i, j}});
            }
        }
        if(pegs.find({i, j + 1}) != pegs.end()){
            if(pegs.find({i, j + 2}) == pegs.end() && 
            is_valid(i, j + 2)){
                moves.push_back({{i, j + 2}, {i, j}});
            }
        }
        if(pegs.find({i, j - 1}) != pegs.end()){
            if(pegs.find({i, j - 2}) == pegs.end() && 
            is_valid(i, j - 2)){
                moves.push_back({{i, j - 2}, {i, j}});
            }
        }
    }        
}

int main(){
    int N;
    cin >> N;
    cout << "HI Q OUTPUT" << "\n";
    for(int i = 0; i < N; i++){
        int ch;
        cin >> ch;
        while(ch != 0){
            int i = pos[ch - 1]/9;
            int j = pos[ch - 1] % 9;
            pegs.insert({i, j});
            cin >> ch;
        }
        calc_moves();
        while (moves.size() > 0){
            pair<pair<int,int>,pair<int,int>> choice = best_move();
            move(choice.first, choice.second);
            calc_moves();            
        }
        int sum = 0;
        for(auto e: pegs){
            sum += v[e.first][e.second];            
        }
        cout << sum << "\n";
        pegs.erase(pegs.begin(), pegs.end());
    }
    cout << "END OF OUTPUT" << "\n";
            
    return 0;
}
