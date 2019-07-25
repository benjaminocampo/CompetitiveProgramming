#include <bits/stdc++.h>
using namespace std;

#define DBG(x) cerr << #x << " = " << (x) << endl
#define MAXN 20
#define VCHARS 21

map<char,char> m;
char valid_chars[VCHARS] = {
    'A','E','H','I','J','L','M','O','S','T','U',
    'V','W','X','Y','Z','1','2','3','5','8'
};


bool is_palindrome(string word, int length){
    int i = 0;
    int j = length - 1;
    bool res = true;
    while(i <= j && res){
        if(word[i] != word[j]){
            res = false;
        }
        i++;
        j--;
    }
    return res;
}

bool is_mirrored(string word, int length){
    string s;
    for(int i = 0; i < length; i++){
        auto it = m.find(word[i]);
        if(it != m.end()){
            s[i] = it->second;
        } else {
            return false;
        }
    }
    int i = 0;
    int j = length - 1;
    bool res = true;
    while(i < length && res){
        if(word[i] != s[j]){
            res = false;
        }
        i++;
        j--;
    }
    return res;
}

int main(){
    for(int i = 0; i < VCHARS; i++){
        char c = valid_chars[i];
        switch(c){
            case 'E': 
                m.insert({c, '3'});
                break;
            case 'J':
                m.insert({c, 'L'});
                break;
            case 'L':
                m.insert({c, 'J'});
                break;
            case 'S':
                m.insert({c, '2'});
                break;
            case 'Z':
                m.insert({c, '5'});
                break;
            case '2':
                m.insert({c, 'S'});
                break;
            case '3':
                m.insert({c, 'E'});
                break;
            case '5':
                m.insert({c, 'Z'});
                break;
            default:
                m.insert({c, c});
                break;
        }
    }

    string word;
    while(cin >> word){
        int length = word.size();
        if(is_palindrome(word, length)){
            if(is_mirrored(word, length)){
                cout << word << " -- is a mirrored palindrome." << "\n"; 
            } else {
                cout << word << " -- is a regular palindrome." << "\n";
            }
        } else {
            if(is_mirrored(word, length)){
                cout << word << " -- is a mirrored string." << "\n";     
            } else {
                cout << word << " -- is not a palindrome." << "\n"; 
            }
        }
        cout << "\n";
    }
}