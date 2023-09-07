#include <bits/stdc++.h>
using namespace std;

bool hansu(int n){
	string s = to_string(n);
	int size = s.size();
	if(size < 3) return true;
	else{
		int diff = s[1]-s[0];
		for(int i=1; i<size-1; i++){
			if(s[i+1] - s[i] != diff) return false;
		}
		return true;
	}
}

int main(){
	int num; cin >> num;
	int cnt=0;
	while(num > 0){
		if(hansu(num) == true) cnt++;
		num--;
	}
	printf("%d", cnt);
	return 0;
}