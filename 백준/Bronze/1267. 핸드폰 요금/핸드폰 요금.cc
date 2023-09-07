#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
	int Y=0, M=0;
	for(int k=0; k<n; k++){
		int t, i=0, j=0; cin >> t;
		while(1){
			if(t > 29*i && t<30*(i+1)){
				Y += 10*(i+1);
				break;
			}
			else i++;
		}
		while(1){
			if(t > 59*j && t<60*(j+1)){
				M += 15*(j+1);
				break;
			}
			else j++;
		}
	}
	if(Y > M) printf("M %d", M);
	else if(M > Y) printf("Y %d", Y);
	else printf("Y M %d", Y);
	return 0;
}