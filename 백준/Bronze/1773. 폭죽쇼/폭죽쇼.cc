#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, c; cin >> n >> c;
	int student[n], time[c]={0,}, cnt=0;;
	for(int i=0; i<n; i++) scanf("%d", &student[i]);
	
	for(int i=0; i<n; i++){
		for(int j=1; j*student[i] <= c; j++){
			if(time[j*student[i]-1] == 0){
				time[j*student[i]-1]++;
				cnt++;
			}
		}
	}
	
	printf("%d", cnt);
	return 0;
}