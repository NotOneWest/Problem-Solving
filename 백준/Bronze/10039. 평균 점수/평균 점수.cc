#include <bits/stdc++.h>
using namespace std;

int main(){
	int sum=0;
	for(int i=0; i<5; i++){
		int n; cin >> n;
		
		if(n<40) sum+=40;
		else sum += n;
	}
	cout << sum/5;
}