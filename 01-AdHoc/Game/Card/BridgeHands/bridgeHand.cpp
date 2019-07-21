#include <bits/stdc++.h>
using namespace std;

#define DBG(x) cerr << #x << " = " << (x) << endl

#define NCARDS 52
#define NPLAYERS 4

string cards[NCARDS] = {
    "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "CT", "CJ", "CQ", "CK", "CA",
    "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "DT", "DJ", "DQ", "DK", "DA",
    "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "ST", "SJ", "SQ", "SK", "SA",
    "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "HT", "HJ", "HQ", "HK", "HA"
    };

char players[NPLAYERS] = {'N', 'E', 'S', 'W'};

int main(){

    map<string, int> mcards;
    map<char, int> mdealers;

    int order[NCARDS];
    vector<int> decks[NPLAYERS];
    
    //Map the cards with a number
    for(int i = 0; i < NCARDS; i++){
        mcards.insert({cards[i], i});
        order[i] = i;
    }
    //Map the players with a number
    for(int i = 0; i < 4; i++){
        mdealers.insert({players[i], i});
    }

    char x;
    cin >> x;
    string s;
    while(x != '#'){
        int dealer = mdealers[x];
        string s1;
        string s2;
        cin >> s1;
        cin >> s2;
        s = s1 + s2;
        int length = s.size();
        int j = 0;
        
        for(int i = 0; i < length; i+=2){
            string card = s.substr(i, 2);
            decks[(j + dealer + 1) % 4].push_back(mcards[card]);
            j++;
        }

        for(int i = 0; i < NPLAYERS; i++){
            sort(decks[i].begin(), decks[i].end());   
        }

        //Start with the player that is in the Sud (S)
        for(int i = 2; i < 6; i++){
            cout << players[i % 4] << ":";
            for(int j = 0; j < 13; j++){
                cout << " ";
                cout << cards[decks[i % 4][j]];
            }
            decks[i % 4].erase(decks[i % 4].begin(), decks[i % 4].end());
            cout << "\n";
        }
        cin >> x;
    }
    return 0;
}