#include <bits/stdc++.h>
using namespace std;

typedef multiset<int>::iterator It;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    set <int> s;
    multiset<int> ms1;
    multiset<int> ms2;
    while(T--){
        int n, m; cin >> n >> m;
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            s.insert(x);
            ms1.insert(x);
        }
        for(int i = 0; i < m; i++){
            int x; cin >> x;
            s.insert(x);
            ms2.insert(x);
        }
        int res = 0;
        for(auto e: s){
            int rep_s1 = ms1.count(e);
            int rep_s2 = ms2.count(e);
            res += abs(rep_s1 - rep_s2);
        }
        cout << res << "\n";
        s.erase(s.begin(), s.end());
        ms1.erase(ms1.begin(), ms1.end());
        ms2.erase(ms2.begin(), ms2.end());
    }
    return 0;
}