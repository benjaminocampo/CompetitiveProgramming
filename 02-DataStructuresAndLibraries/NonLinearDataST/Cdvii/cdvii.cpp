#include <bits/stdc++.h>
using namespace std;

struct license_photo {
	string license;
	string date;
	string type;
	int km;
};

typedef struct license_photo license_photo;

int isEmpty(const char *line){
    /* check if the string consists only of spaces. */
    while (*line != '\0')
    {
        if (isspace(*line) == 0)
            return 0;
        line++;
    }
    return 1;
}

int parse_time(string s){
	string tmp = s.substr(6, 2);
	int time = stoi(tmp);
	return stoi(tmp);
}

double calc_bill(int km, int toll){
	double cents = (double)(km*toll);
	return (cents/100);
}

bool goes_before(license_photo p1, license_photo p2){
	if(p1.license < p2.license) return true;
	else if(p1.license == p2.license) return (p1.date <= p2.date);
	else {
		return false;
	}
}


int main(){
	int Q; scanf("%d", &Q);
	char line[64];
	fgets(line, 64, stdin);
	int tmp = Q;
	while(Q--){
		if(Q != tmp - 1){
			cout << "\n";
		}
		int tolls[24];
		for(int i = 0; i < 24; i++){
			int x; scanf("%d", &x);
			tolls[i] = x;
		}
		vector<license_photo> photos;
		fgets(line, 64, stdin);
		while((fgets(line, 64, stdin) != NULL) && (isEmpty(line) == 0)){
			char l[64], d[64], t[64]; 
			int km;
			if(sscanf(line, "%s %s %s %d", l, d, t, &km) == 4){			
				string license(l);
				string date(d);
				string type(t);
				struct license_photo s;
				s.license = license;
				s.date = date;
				s.type = type;
				s.km = km;
				photos.push_back(s);
			}
		}
		
		sort(photos.begin(), photos.end(), goes_before);
		/*
		for(int i = 0; i < photos.size(); i++){
			cout << photos[i].license << " " << photos[i].date << " " << photos[i].type << " " << photos[i].km << "\n";
		}
		*/
		
		int i = 0;
		vector<pair<string, double>> wallets;
		int last = -1;
		string actual = "";
		while(i < photos.size() - 1){
			license_photo current = photos[i];
			if(current.license == photos[i+1].license 
			    && current.type == "enter" 
				&& photos[i+1].type == "exit"
			){
				if(current.license != actual){
					last++;
					wallets.push_back({current.license, 2});
					actual = current.license;
				}
				int time = parse_time(current.date);
				wallets[last].second += calc_bill(abs(photos[i+1].km - current.km), tolls[time]) + 1;
				i+=2;
			} else {
				i+=1;
			}
		}
		for(int k = 0; k < wallets.size(); k++){
			cout << wallets[k].first << " $" << fixed << setprecision(2) << wallets[k].second << "\n";
		}
		photos.erase(photos.begin(), photos.end());
	}
	return 0;
}
