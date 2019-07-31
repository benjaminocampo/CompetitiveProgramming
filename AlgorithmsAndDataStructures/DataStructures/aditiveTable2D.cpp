#include <bits/stdc++.h>
using namespace std;

#define MAXN 500
#define MAXM 500

int A[MAXN][MAXM];

void fill_aditive_table2D(int n, int m, int **v){
    for(int i = 0; i <= n; i++){
        A[i][0] = 0;
    }
    for(int j = 0; j <= m; j++){
        A[0][j] = 0;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            A[i+1][j+1] = v[i][j] + A[i][j+1] + A[i+1][j] - A[i][j];
        }
    }
}

int main(){
    int n;
    int m;
    cin >> n >> m;

    int **v = (int **) malloc(n*sizeof(int*));
    for(int i = 0; i < n; i++){
        v[i] = (int *) malloc(m*sizeof(int));
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int x;
            cin >> x;
            v[i][j] = x;
        }
    }

    fill_aditive_table2D(n, m, v);

    pair<int,int> L[4] = {{1, 3}, {0, 3}, {2, 4}, {0, 1}};
    pair<int,int> R[4] = {{1, 3}, {1, 2}, {1, 3}, {2, 4}};

    for(int i = 0; i < 4; i++){
        int i1 = L[i].first;
        int i2 = L[i].second;
        int j1 = R[i].first;
        int j2 = R[i].second;
        cout << "[" << i1 << ", " << i2 << ")x";
        cout << "[" << j1 << ", " << j2 << "): ";
        cout << A[i2][j2] - A[i1][j2] - A[i2][j1] + A[i1][j1] << "\n";
    }

    return 0;
}