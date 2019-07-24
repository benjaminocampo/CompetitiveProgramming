#include <bits/stdc++.h>
using namespace std;

#define DBG(x) cerr << #x << " = " << (x) << endl

set<int> king_moves(pair<int,int> p){
    int i = p.first;
    int j = p.second;
    set<int> moves;
    if(i == 0){
        moves.insert((i + 1)*8 + j);
    } else if(i == 7){
        moves.insert((i - 1)*8 + j);
    } else {
        moves.insert((i + 1)*8 + j);
        moves.insert((i - 1)*8 + j);
    }
    if(j == 0){
        moves.insert(i*8 + (j + 1));
    } else if(j == 7){
        moves.insert(i*8 + (j - 1));
    } else {
        moves.insert(i*8 + (j + 1));
        moves.insert(i*8 + (j - 1));
    }
    return moves;
}

set<int> queen_moves(pair<int,int> p, int i_k, int j_k){
    int i = p.first;
    int j = p.second;
    set<int> moves;
    if(i == 0){
        for(int t = 1; t < 8; t++){
            moves.insert(t*8 + j);
        }
    } else if(i == 7){
        for(int t = 6; t >= 0; t--){
            moves.insert(t*8 + j);
        }
    } else {
        for(int t = i + 1; t < 8; t++){
            moves.insert(t*8 + j);
        }
        for(int t = i - 1; t >= 0; t--){
            moves.insert(t*8 + j);
        }        
    }
    if(j == 0){
        for(int t = 1; t < 8; t++){
            moves.insert(i*8 + t);
        }
    } else if(j == 7){
        for(int t = 6; t >= 0; t--){
            moves.insert(i*8 + t);
        }
    } else {
        for(int t = j + 1; t < 8; t++){
            moves.insert(i*8 + t);
        }
        for(int t = j - 1; t >= 0; t--){
            moves.insert(i*8 + t);
        }
    }

    if(i == i_k){
        if(j < j_k){
            for(int t = j_k; t < 8; t++){
                moves.erase(moves.find(i*8 + t));
            }
        } else if(j > j_k){
            for(int t = j_k; t >= 0; t--){
                moves.erase(moves.find(i*8 + t));
            }
        }
    }

    if(j == j_k){
        if(i < i_k){
            for(int t = i_k; t < 8; t++){
                moves.erase(moves.find(t*8 + j));
            }
        } else if(i > i_k){
            for(int t = i_k; t >= 0; t--){
                moves.erase(moves.find(t*8 + j));
            }
        }
    }

    return moves;
}

bool is_included(set<int> p, set<int> q){
    bool res = true;
    for (auto e: p){
        if(q.find(e) == q.end()) {
            res = false;
            break;
        }
    }
    return res;    
}

int main(){
    int k, q, mq;
    while(scanf("%d %d %d", &k, &q, &mq) != EOF){
        int i_k = k/8;
        int j_k = k % 8;
        int i_q = q/8;
        int j_q = q % 8;
        int i_mq = mq/8;
        int j_mq = mq % 8;
        set<int> k_moves = king_moves({i_k, j_k});
        set<int> q_moves = queen_moves({i_q, j_q}, i_k, j_k);
        set<int> mq_moves = queen_moves({i_mq, j_mq}, i_k, j_k);
        if(k == q){
            cout << "Illegal state" << "\n";
        } else if(mq == k || (q_moves.find(mq) == q_moves.end())){
            cout << "Illegal move" << "\n";
        } else if(k_moves.find(mq) != k_moves.end()){
            //Check if the queen's move is on the king's moves (if it is allowed)
            cout << "Move not allowed" << "\n";
        } else if(is_included(k_moves, mq_moves)){
            cout << "Stop" << "\n";
        } else {
            cout << "Continue" << "\n";
        }
    }
    return 0;
}