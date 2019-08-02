#include <bits/stdc++.h>
using namespace std;

#define MAXN 500
#define K 9     // log2(MAXN);

int M[MAXN][K];

// f is the associative operator
int f(int a, int b){
    return min(a, b);
}


void fill_sparse_table(int N, const int *v){
    const int LAST_LEVEL = 31 - __builtin_clz(N) + 1;
    for (int i = 0; i < N; i++) M[i][0] = v[i];
    
    for (int k = 0; k < LAST_LEVEL; k++) {
            const int LENGTH = (1<<k);
        for (int i = 0; i <= N - 2 * LENGTH; i++)
            M[i][k+1] = f(M[i][k], M[i + LENGTH][k]);
    }
}


int main(){
    int v[11] = {10, 5, 7, 10, 2, 4, 8, 6, 3, 9, 4};
    const int N = 11;

    fill_sparse_table(N, v);

    int L[6] = {2, 4, 3, 1, 7, 1};
    int R[6] = {3, 8, 5, 2, 11, 4};

    for(int i = 0; i < 6; i++){
        int k = 31 - __builtin_clz(R[i] - L[i]);
        cout << "[" << L[i] << ", " << R[i] << "): "; 
        cout << f(M[L[i]][k], M[R[i] - (1 << k)][k]) << "\n";
    }

    return 0;
}