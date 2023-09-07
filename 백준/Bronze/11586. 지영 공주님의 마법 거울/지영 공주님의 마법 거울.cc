#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n, k;
    cin >> n;
	char mirror[n][n+1];
	for(int i=0; i<n; i++) cin >> mirror[i];
	cin >> k;
	
	if(k==1){
		for(int i=0; i<n; i++) {
			printf("%s", mirror[i]);
			if(i<n-1) printf("\n");
		}
	}
	else if(k==2){
		for(int i=0; i<n; i++){
			for(int j=1; j<=n; j++) cout << mirror[i][n-j];
			if(i<n-1) cout << "\n";
		}
	}
	else{
		for(int i=1; i<=n; i++){
			cout << mirror[n-i];
			if(i<n) cout << "\n";
		}
	}
	
	return 0;
}