#include <bits/stdc++.h>
using namespace std;

#define MAXNTRACKS 20

int duration[MAXNTRACKS + 1];

/*
*	Calculate the highest memory usage achievable
* 	of a tape of capacity n with tracks 1, 2, ... , k
*/
int cd(int k, int n){

	/* Allocate memory for memorization */
	int **dp = (int **)malloc((k + 1)*sizeof(int*));
	for(int i = 0; i <= k ; i++){
		dp[i] = (int *)malloc((n + 1)*sizeof(int));
	}
	
	
	/* Create the table */
	for(int i = 0; i <= k; i++) dp[i][0] = 0;
	for(int j = 1; j <= n; j++) dp[0][j] = 0;
	for(int i = 1; i <= k; i++){
		for(int j = 1; j <= n; j++){
			if(duration[i] <= j){ 
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-duration[i]] + duration[i]);
			}
			else { dp[i][j] = dp[i-1][j]; }
		}
	}
	
	/* Rebuilding the answer using the table */
	vector<int> cds;
	int r = k;
	int s = n;
	while(dp[r][s] > 0){
		if(dp[r][s] != dp[r-1][s]){
			cds.push_back(duration[r]);
			s -= duration[r];
		}
		r--;
	}
	
	int length = cds.size();
	for(int i = length - 1; i >= 0; i--){
		printf("%d ", cds[i]);
	}
	
	return dp[k][n];
}


int main(){
	int n, ntrucks;
	while(scanf("%d %d", &n, &ntrucks) != EOF){
		for(int i = 1; i <= ntrucks; i++){
			int d; scanf("%d", &d);
			duration[i] = d;
		}
		printf("sum:%d\n", cd(ntrucks, n));
	}
	return 0;
}
