#include <bits/stdc++.h>
using namespace std;

int sosu(int number){
	if(number == 1) return 0;
	else if(number == 2) return 1;
	else {
		for(int i=2; i<number; i++){
			if(number%i == 0) return 0;
		}
	}
	return 1;
}

int main(){
	int n,m; cin >> n >> m;
	int num[m-n+1]={0,};
	for(int i=n; i<m+1; i++){
		if(sosu(i) == 1) num[i-n]++;
	}
	int sum=0, loc=-1;
	for(int i=0; i<m-n+1; i++){
		if(num[i] == 1){
			if(loc == -1) loc = i;
			sum += i+n;
		}
	}
	if(sum == 0) printf("-1");
	else{
		printf("%d\n", sum);
		printf("%d", loc+n);
	}
	return 0;
}