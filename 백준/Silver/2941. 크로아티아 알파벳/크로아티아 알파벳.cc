#include <bits/stdc++.h>
using namespace std;

int main(){
	string s; cin >>s;
	int count=0;
	for(int i=0; i<s.size(); i++){
		if(s[i] == 'c'){
			if(s[i+1] == '=' || s[i+1] == '-') i++;
		}
		else if(s[i] == 'd'){
			if(s[i+1] =='z' && s[i+2] == '=') i+=2;
			else if(s[i+1] == '-') i++;
		}
		else if (s[i] == 'l' || s[i] == 'n'){
			if(s[i+1] == 'j') i++;
		}
		else if(s[i] == 's' ||s[i] == 'z'){
			if(s[i+1] == '=') i++;
		}
		count++;
	}
	printf("%d", count);
	return 0;
}