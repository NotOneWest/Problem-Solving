#include <bits/stdc++.h>
using namespace std;


int main(){
	int l,r,a; cin >> l >> r >> a;
	int players=0;
	if(l<r){
		if(l+a <= r) players = (l+a)*2;
		else{
			players = 2*( r + (a-(r-l))/2 );
		} 
	}
	else if(r<l){
		if(r+a <= l) players = (r+a)*2;
		else{
			players = 2*( l + (a-(l-r))/2 );
		}
	}
	else{
		players = (l+a/2)*2;
	}
	printf("%d", players);
	return 0;
}