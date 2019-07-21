#include<bits/stdc++.h>
using namespace std;

#define DBG(x) cerr << #x << " = " << (x) << endl

int main(){
    char c;
    bool openQuote = true;
    while(scanf("%c", &c) != EOF){
        if(c == '"'){
            if(openQuote){
                printf("``");
                openQuote = false;
            } else {
                printf("''");
                openQuote = true;
            }
        } else {
            printf("%c", c);
        }
    }
    return 0;
}
