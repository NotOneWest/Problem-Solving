#include <bits/stdc++.h>
using namespace std;

int main(){
    int stu[30]={0,};
    for(int i=0; i<28; i++){
    	int n; cin >> n;
    	stu[n-1]++;
	}
	for(int i=0; i<30; i++){
    	if(stu[i] == 0) printf("%d\n" ,i+1);
	}
	return 0;
}