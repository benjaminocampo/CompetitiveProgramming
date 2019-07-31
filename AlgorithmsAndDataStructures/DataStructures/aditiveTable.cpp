#include <bits/stdc++.h>
using namespace std;

#define MAXN 500

// f is the associative operator
int f(int a, int b){
    return (a + b);
}

void fill_aditive_table(int *A, int n, const int *v){
    A[0] = 0;
    for(int i = 1; i < n; i++){
        A[i + 1] = v[i] + A[i];
    }
}

int main(){
    int v[11] = {10, 5, 7, 10, 2, 4, 8, 6, 3, 9, 4};
    const int n = 11;

    int A[MAXN + 1];

    fill_aditive_table(A, n, v);

    int L[6] = {2, 4, 3, 1, 7, 1};
    int R[6] = {3, 8, 5, 2, 11, 4};

    for(int i = 0; i < 6; i++){
        cout << "[" << L[i] << ", " << R[i] << "): "; 
        cout << f(A[R[i]], (-1)*A[L[i]]) << "\n";
    }

    return 0;
}