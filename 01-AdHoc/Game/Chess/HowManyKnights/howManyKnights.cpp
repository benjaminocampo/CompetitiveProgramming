#include <bits/stdc++.h>
using namespace std;

#define DBG(x) cerr << #x << " = " << (x) << endl

int main(){
    int i, j;
    cin >> i >> j;
    while(i != 0 || j!= 0){
        if(i == 0 || j == 0){
            cout << 0 << " knights may be placed on a "<< i << " row " << j << " column board.";
            cout << "\n";
        }
        else if(i == 1){
            cout << j << " knights may be placed on a "<< i << " row " << j << " column board.";
            cout << "\n";
        } 
        else if(i == 2){
            if(j == 1){
                cout << 2 << " knights may be placed on a "<< i << " row " << j << " column board.";
                cout << "\n";
            } else {
                if(j % 2 == 0){
                    int squares = j/2;
                    if(squares % 2 == 0){
                        cout << (squares/2)*4 << " knights may be placed on a "<< i << " row " << j << " column board.";
                        cout << "\n";
                    } else {
                        cout << (1 + (squares/2))*4 << " knights may be placed on a "<< i << " row " << j << " column board.";
                        cout << "\n";
                    }
                } else {
                    int squares = j/2;
                    if(squares % 2 == 0){
                        cout << (squares/2)*4 + 2 << " knights may be placed on a "<< i << " row " << j << " column board.";
                        cout << "\n";
                    } else {
                        cout << (squares/2 + 1)*4 << " knights may be placed on a "<< i << " row " << j << " column board.";
                        cout << "\n";
                    }
                }
            }
        } else if(j == 1){
            cout << i << " knights may be placed on a "<< i << " row " << j << " column board.";
            cout << "\n";
        } else if(j == 2){
            if(i % 2 == 0){
                int squares = i/2;
                if(squares % 2 == 0){
                    cout << (squares/2)*4 << " knights may be placed on a "<< i << " row " << j << " column board.";
                    cout << "\n";
                } else {
                    cout << (1 + (squares/2))*4 << " knights may be placed on a "<< i << " row " << j << " column board.";
                    cout << "\n";
                }
            } else {
                int squares = i/2;
                if(squares % 2 == 0){
                    cout << (squares/2)*4 + 2 << " knights may be placed on a "<< i << " row " << j << " column board.";
                    cout << "\n";
                } else {
                    cout << (squares/2 + 1)*4 << " knights may be placed on a "<< i << " row " << j << " column board.";
                    cout << "\n";
                }
            }
        }
        else {
            if((i*j) % 2 == 0){
                cout << (i*j)/2 << " knights may be placed on a "<< i << " row " << j << " column board.";
                cout << "\n";
            } else {
                cout << (i*j)/2 + 1 << " knights may be placed on a "<< i << " row " << j << " column board.";
                cout << "\n";
            }
        }
        cin >> i >> j;
    }
}