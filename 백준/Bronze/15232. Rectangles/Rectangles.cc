#include <bits/stdc++.h>
using namespace std;


int main(){
	int r,c; cin >> r >> c;
	for(int i=0; i<r; i++){
		for(int i=0; i<c; i++) printf("*");
		if(i<r-1) printf("\n");
	}
	return 0;
}