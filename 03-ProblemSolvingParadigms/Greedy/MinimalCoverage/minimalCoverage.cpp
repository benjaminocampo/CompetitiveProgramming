#include <bits/stdc++.h>
using namespace std;
#define INF -500001

bool goes_before(pair<int,int> p1, pair<int,int> p2){
	if(p1.second > p2.second) return true;
	else if(p1.second == p2.second) return p1.first >= p2.first;
	else {
		return false;
	}
}

int main(){
	int Q; scanf("%d", &Q);
	char line[10];
	while(Q--){
		fgets(line, 10, stdin);
		int m; scanf("%d", &m);
		int l, r;
		vector<pair<int,int>> p;
		while(scanf("%d %d", &l, &r) ==2 && (l != 0 || r != 0)){
			p.push_back({l, r});
		}
		int length = p.size();
		sort(p.begin(), p.end());
		pair<int,int> selected; selected.second = INF;
		int currentL = 0;
		if(selected.first > currentL){
			printf("0\n");
			continue;			
		}
		vector<pair<int,int>> res;
		int i = 0;
		while(i < length){
			if(p[i].first <= currentL){ 		
				if(selected.second < p[i].second){
					selected = p[i];
				}
				i++;
			} else {
				if(selected.first <= currentL && selected.second >= currentL){
					res.push_back(selected);
					currentL = selected.second;
					selected.second = INF;
				} else {
					break;
				}
			}
			if(currentL >= m) break;
		}
		if(selected.first <= currentL && selected.second >= currentL){
			res.push_back(selected);
			currentL = selected.second;
			selected.second = INF;
		}
		if(currentL >= m){
			sort(res.begin(), res.end());
			printf("%d\n", res.size());
			int length_res = res.size();
			for(int i = 0; i < length_res; i++){
				printf("%d %d\n", res[i].first, res[i].second);
			}
		} else {
			printf("0\n");
		}
		printf("\n");
	}
}
