#include <bits/stdc++.h>
using namespace std;

// f is the associative operator
int f(int a, int b){
    return min(a, b);
}

void fill_sparse_table(int **M, int N, const int *v, const int LAST_LEVEL){
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

    int **M = (int **) malloc(N*sizeof(int*));
    const int LAST_LEVEL = 31 - __builtin_clz(N);
    for(int i = 0; i < N; i++){
        M[i] = (int *) malloc(LAST_LEVEL*sizeof(int));
    }
    fill_sparse_table(M, N, v, LAST_LEVEL);

    int L[6] = {2, 4, 3, 1, 7, 1};
    int R[6] = {3, 8, 5, 2, 11, 4};

    for(int i = 0; i < 6; i++){
        int k = 31 - __builtin_clz(R[i] - L[i]);
        cout << "[" << L[i] << ", " << R[i] << "): "; 
        cout << f(M[L[i]][k], M[R[i] - (1 << k)][k]) << "\n";
    }

    return 0;
}