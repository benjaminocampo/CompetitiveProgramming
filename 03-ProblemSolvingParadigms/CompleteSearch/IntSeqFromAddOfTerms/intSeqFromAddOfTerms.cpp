#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

#define MAXNCOEF 20
#define DBG(x) cerr << #x << " = " << (x) << endl

ull bin_exp(ull a, ull e){
    if (e == 0) return 1;
    else if(e % 2 == 0) return bin_exp((a*a), e/2);
    else {
        return (a*bin_exp(a, e - 1));
    }
}


ull calc_num_of_seq(ull x, ull degree, ull *coef){
	ull ans = 0;
	for(ull i = 0; i <= degree; i++){
		ans += coef[i]*bin_exp(x, i);
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
	int queries; cin >> queries;
	ull coef[MAXNCOEF];
	vector<ull> seq_b;
	while(queries--){
		ull degree; cin >> degree;
		ull ncoef = degree + 1;
		for(ull i = 0; i < ncoef; i++){
			ull c; cin >> c;
			coef[i] = c;
		}
		ull d; cin >> d;
		ull k; cin >> k;
		ull j = 1;
		ull t = 0;
		while(t < k){
			ull a = calc_num_of_seq(j, degree, coef);
			seq_b.push_back(a);
			t += j*d;
			j++;
		}
		cout << seq_b[seq_b.size() - 1] << "\n";
	}
}
