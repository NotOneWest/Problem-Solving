#include <bits/stdc++.h>
using namespace std;

int main(){
	string s; cin >>s;
	int size = s.size(), t=0;
	for(int i=0; i<size; i++){
		if(s[i] < 68) t+=3;
		else if(s[i] > 67 && s[i] < 71) t+=4;
		else if(s[i] > 70 && s[i] < 74) t+=5;
		else if(s[i] > 73 && s[i] < 77) t+=6;
		else if(s[i] > 76 && s[i] < 80) t+=7;
		else if(s[i] > 79 && s[i] < 84) t+=8;
		else if(s[i] > 83 && s[i] < 87) t+=9;
		else t+=10;
	}
	printf("%d", t);
	return 0;
}