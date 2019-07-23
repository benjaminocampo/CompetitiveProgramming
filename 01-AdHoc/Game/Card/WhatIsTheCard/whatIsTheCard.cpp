#include <bits/stdc++.h>
using namespace std;

#define DBG(x) cerr << #x << " = " << (x) << endl

#define NCARDS 52

string cards[NCARDS] = {
    "2C", "3C", "4C", "5C", "6C", "7C", "8C", "9C", "TC", "JC", "QC", "KC", "AC",
    "2D", "3D", "4D", "5D", "6D", "7D", "8D", "9D", "TD", "JD", "QD", "KD", "AD",
    "2S", "3S", "4S", "5S", "6S", "7S", "8S", "9S", "TS", "JS", "QS", "KS", "AS",
    "2H", "3H", "4H", "5H", "6H", "7H", "8H", "9H", "TH", "JH", "QH", "KH", "AH"
    };

int main(){
    map<string, int> cards_values;

    //Map a card with a value
    for(int i = 0; i < NCARDS; i++){
        char c = cards[i][0];
        if(c != 'T' && c != 'J' && c !='Q' && c != 'K' && c != 'A'){
            int value = c - '0';
            cards_values.insert({cards[i], value});
        } else {
            cards_values.insert({cards[i], 10});
        }
    }
    int Q;
    cin >> Q;
    deque<string> heap, hand;
    for(int test = 1; test <= Q; test++){
        for(int i = 0; i < 27; i++){
            string card;
            cin >> card;
            heap.push_back(card);
        }
        for(int i = 27; i < 52; i++){
            string card;
            cin >> card;
            hand.push_back(card);
        }
        int y = 0;
        int steps = 3;
        while(steps--){
            string card = heap.back();
            heap.pop_back();
            int x = cards_values[card];
            y += x;
            int throw_away = 10 - x;
            for(int j = 0; j < throw_away; j++){
                heap.pop_back();
            }
        }
        for(int j = 0; j < 25; j++){
            string c = hand.front();
            heap.push_back(c);
            hand.pop_front();
        }

        cout << "Case " << test << ": " << heap[y - 1] << "\n";
        heap.erase(heap.begin(), heap.end());
    }
}