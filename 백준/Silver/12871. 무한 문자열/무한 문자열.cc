#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int main(){
	string s; cin>> s;
	string t; cin >> t;
	
	int slen = s.size();
	int tlen = t.size();
	int answer = 0, check = 0;
	
	for(int i=1; i<=slen; i++){
		string copy = s.substr(0,i);
		string s2 = s;
		int clen = copy.size(), s2len = s2.size();
		
		for(int j=0; j<s2len/clen+1; j++){
			string copys = s2.substr(0, clen);
			if(copy == copys){
				check = 1;
				s2 = s2.substr(clen);
			}
			else {
				if(s2.size() == 0) answer = 1;
				else check = 0;
			} 
		}
		if(check == 1){
			s = copy;
			break;
		}
	}
	slen = s.size();
	
	for(int i=0; i<tlen/slen+1; i++){
		string copy = t.substr(0, slen);
		if(s == copy){
			answer = 1;
			t = t.substr(slen);	
		}
		else {
			if(t.size() == 0) answer = 1;
			else answer = 0;
		}
	}
	
	printf("%d", answer);
	
	return 0;
}