#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    for(int i=0; i<t; i++){
    	int yon=0, kor=0;
    	for(int j=0; j<9; j++){
    		int y,k; cin >> y >> k;
    		yon+=y; 
			kor+=k;
		}
		if(yon > kor) printf("Yonsei\n");
		else if (yon < kor) printf("Korea");
		else printf("Draw\n");
	}
    return 0;
}