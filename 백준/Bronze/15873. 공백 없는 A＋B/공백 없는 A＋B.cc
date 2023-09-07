#include <bits/stdc++.h>
using namespace std;

int main(){
	string s; cin >> s;
	int sum;
	
	if(s.size() == 2) sum = s[0]+s[1]-'0'-'0';
	else if(s.size() == 3){
		string a = s.substr(0,2);
		if(atoi(a.c_str()) > 10){
			a = s.substr(1,2);
			sum = s[0] - '0' + atoi(a.c_str());				
		}
		else sum = s[2] - '0' + atoi(a.c_str());
	}
	else{
		string a = s.substr(0,2);
		string b = s.substr(2,2);
		sum = atoi(a.c_str()) + atoi(b.c_str());
	}
	printf("%d", sum);
	return 0;
}