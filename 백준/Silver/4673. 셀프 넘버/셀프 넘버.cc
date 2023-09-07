#include <bits/stdc++.h>
using namespace std;

int d(int n){
	string s = to_string(n);
	int size = s.size(), selfnum=n;
	for(int i=0; i<size; i++){
		selfnum += n%10;
		n = n/10;
	}
	return selfnum;
}

int main(){
	int sn[10000]={0,}, n=1;
	
	while(n<10001){
		if(d(n)-1 <= 10001) sn[d(n)-1]++;
		n++;
	}
	for(int i=0; i<10000; i++){
		if(sn[i] == 0) printf("%d\n", i+1);
	}
	return 0;
}