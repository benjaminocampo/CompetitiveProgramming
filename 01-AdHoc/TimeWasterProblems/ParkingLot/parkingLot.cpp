#include <bits/stdc++.h>
using namespace std;

int distance(int vacant, int car){
	if(car <= vacant) return vacant - car;
	else {
		return ((20 - car) + vacant);	
	}
}

int get_line(){
	string s;
	cin >> s;
	if(s == "\n") return -1;
	int x = atoi(s.c_str());
	/*
	scanf("%c", &c);
	if(c != '\n'){
		x = x*10 + atoi((const char*)c);
	}*/
	char l;
	cin >> l;
	return x;	
}

vector<int> get_vacancies(){
	vector<int> v;
	int x;
	while(x = get_line() && x != -1){
		cout << x << "\n";		
		v.push_back(x);
		
	} 
	return v;
}

int main(){
	int T; cin >> T;
	
	for(int u = 0; u < T; u++){
		int x; cin >> x;
		vector<pair<int,int>> p;
		vector<int> v;
		vector<pair<int,int>> cars;
		int z = 0;
		while(x != 99){
			cars.push_back({x, -1});
			p.push_back({x, z});
			z++;
			cin >> x;
		}
		/*
		for(int r = 0; r < p.size(); r++){
			cout << "{"<< p[r].first << ", " << p[r].second << "} ";
		}
		cout << "\n";
		*/
		v = get_vacancies();
		return 0;
		for(int w = 0; w < v.size(); w++){
			cout << v[w] << " ";
		}
		cout << "\n";

		for(int i = 0; i < v.size(); i++){
			int minimum = 21;
			int indx = 0;
			for(int j = 0; j < p.size(); j++){
				int m = distance(v[i], p[j].first);
				if(minimum > m){
					minimum = m;
					indx = j;
				}			
			}
			if(p.size() == 0) break;
			cars[p[indx].second].second = v[i];
			p.erase(p.begin() + indx);
			for(int k = 0; k < p.size(); k++){
				p[k].first = (p[k].first + minimum) % 20;
			}
		}
		for(int i = 0; i < cars.size(); i++){
			if(cars[i].second == -1){
				cout << "Original position " << cars[i].first <<  " did not park\n";	
			} else {
				cout << "Original position " << cars[i].first <<  " parked in " << cars[i].second << "\n";
			}
		}
	}
	return 0;
}
