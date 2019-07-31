#include <bits/stdc++.h>
using namespace std;

#define MAXN 500

void init_uf(int *rep, int length){
    fill(rep, rep + length, -1);
}

bool is_rep(int *rep, int i){
    return (rep[i] < 0);
}

int find(int *rep, int x){
    if(rep[x] < 0)
        return x;
    return rep[x] = find(rep, rep[x]);
}

// Join two disjointed sets with reprentatives u and v such that
// u is not equal to v
void union_set(int *rep, int u, int v){
    if(rep[u] >= rep[v]){
        rep[v] += rep[u];
        rep[u] = v;
    } else {
        rep[u] += rep[v];
        rep[v] = u;
    }
}

int main(){
    int rep[MAXN];
    int p[9] = {-19, 1, 12, 3, 34, 5, 6, 7, 8};
    init_uf(rep, 9);
    
    for(int i = 0; i < 4; i++){
        int u = find(rep, i);
        int v = find(rep, i + 1);
        if(u != v){
            union_set(rep, u, v);
        }
    }
    for(int i = 5; i < 8;i++){
        int u = find(rep, i);
        int v = find(rep, i + 1);
        if(u != v){
            union_set(rep, u, v);
        }
    }

    for(int i = 0; i < 9; i++){
        cout << "Elem: " << p[i] << "- " << "Rep: " << rep[i] << "\n";
    }

    return 0;
}