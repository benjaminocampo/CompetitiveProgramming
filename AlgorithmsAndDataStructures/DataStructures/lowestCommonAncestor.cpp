#include <bits/stdc++.h>
using namespace std;
#define DBG(x) cerr << #x << " = " << (x) << endl
#define MAX 1001 
  
// Adjacency list representation of tree 
vector<int> graph[MAX];  
  
// Visited array to keep track visited  
// nodes on tour 
int vis[MAX];  
  
// Array to store Euler's Tour 
int Euler[2 * MAX];

// Array to store how deep is a node in the tree.
int D[2*MAX];

// Array to store the first appearance of a node u in the array Euler
int L[MAX];

void euler_tree_rec(int u, int &indx, int &level){ 
    vis[u] = 1;
    L[u] = indx; 
    D[indx] = level;
    Euler[indx++] = u; 
    for (auto it : graph[u]){ 
        if (!vis[it]){ 
            level++;
            euler_tree_rec(it, indx, level);
            D[indx] = --level; 
            Euler[indx++] = u;
        } 
    } 
}

void euler_tree(int u){
    int index = 0;
    int level = 0;
    euler_tree_rec(u, index, level); 
}

/*
* Allocate memory for a matrix M[n][k] of pairs where n is the amount of nodes
* in the graph and k is such that k >= log2(n) + 1.
* It will save the profoundness of a node and its position in the Euler's trip
* for the graph.
*/
pair<int,int> **create_sparse_table(int n){
    pair<int,int> **M = (pair<int,int> **) malloc(n*sizeof(pair<int,int>*));
    const int LAST_LEVEL = 31 - __builtin_clz(n) + 1;
    for(int i = 0; i < n; i++){
        M[i] = (pair<int,int>*) malloc(LAST_LEVEL*sizeof(pair<int,int>));
    }
    return M;
}

void destroy_sparse_table(pair<int,int> **M, int n){
    for(int i = 0; i < n; i++){
        free(M[i]);
    }
    free(M);
}

void fill_sparse_table(pair<int,int> **M, int N, const int *v, const int LAST_LEVEL){
    for (int i = 0; i < N; i++) M[i][0] = {v[i], i};
    
    for (int k = 0; k < LAST_LEVEL; k++) {
            const int LENGTH = (1<<k);
        for (int i = 0; i <= N - 2 * LENGTH; i++)
            M[i][k+1] = min(M[i][k], M[i + LENGTH][k]);
    }
}

/**
*   Return the minimum element in D in the range [a, b)
*   with M the sparse table of D, the array of profoundness of
*   the array Euler.
**/ 
int rmq(int a, int b, pair<int,int> **M){
    const int k = 31 - __builtin_clz(b - a);
    if(M[a][k] <= M[b - (1 << k)][k]){
        return M[a][k].second;
    } else{
        return M[b - (1 << k)][k].second;
    }
}

/**
*   Return the lowest common ancestor between nodes i and j
*   (i and j must be nodes in "graph")
*   M must be the sparse table of D, the array of profoundness of
*   the array Euler.
*   1 <= i, j <= n
**/ 
int lca(int i, int j, pair<int,int> **M){
    return Euler[rmq(min(L[i], L[j]), max(L[i], L[j]) + 1, M)];   
}
    
int main() {
    int n, m; cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    euler_tree(1);

    pair<int,int> **M = create_sparse_table(2*n - 1);
    const int LAST_LEVEL = 31 - __builtin_clz(n) + 1;
    fill_sparse_table(M, 2*n - 1, D, LAST_LEVEL); 

    destroy_sparse_table(M, 2*n - 1);

    return 0; 
} 