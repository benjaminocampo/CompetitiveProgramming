#include <bits/stdc++.h>
using namespace std;

#define MAXN 7

int ft[MAXN+1];


void upd(int i0, int v){ // add v to i0th element (0-based)
    for(int i=i0+1;i<=MAXN;i+=i&-i)ft[i]+=v;
}

void fill_ft(int N, int *v){
    for(int i = 0; i < N; i++){
        upd(i, v[i]);
    }
}

int get(int i0){ // get sum of range [0,i0)
    int r=0;
    for(int i=i0;i;i-=i&-i){
        r+=ft[i];
        cout << i << "\n";
    }
        return r;
}

int get_sum(int i0, int i1){ // get sum of range [i0,i1) (0-based)
    return get(i1)-get(i0);
}

int main(){
    int v[7] = {2,5,7,3,4,8,10};
    const int N = 7;

    fill_ft(N, v);
    for(int i = 0; i < N + 1; i++){
        cout << ft[i] << " ";
    }
    cout << "\n";

    cout << "[" << 2 << ", " << 6 << "): "; 
    cout << get_sum(2,6) << "\n";

    return 0;
}