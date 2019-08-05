#include <bits/stdc++.h>
using namespace std;
#define MAXN 300000

int uf[MAXN];

void init_uf(int n){
    fill(uf, uf+n, -1);
}

int find(int x){
    if(uf[x] < 0)
        return x;
    return uf[x] = find(uf[x]);
}
void join(int x, int y){ // union es palabra reservada de C++ :(
    x = find(x); y = find(y);
    if(x == y)
        return;
    if(uf[x] > uf[y])
        swap(x,y);
    uf[x] += uf[y];
    uf[y] = x;
}

int min_array(int n){
    int m = 1000000000; // + infinity
    for(int i = 0; i < n; i++){
        if(uf[i] < m) m = uf[i];        
    }
    return m;
}

int main(){
    int queries;
    cin >> queries;
    for(int i = 0; i < queries; i++){
        int n, m;
        cin >> n >> m;
        init_uf(n);
        for(int j = 0; j < m; j++){
            int x, y;
            cin >> x >> y;
            join(x - 1, y - 1);
        }
        cout << abs(min_array(n)) << "\n";                
    }
    return 0;
}
