#include <bits/stdc++.h>
using namespace std;

int main(){
	string s; cin >>s;
	int size = s.size(), max=0, index=0, chars[26]={0,};
	
	for(int i=0; i<size; i++){
		if(s[i]-97 >=0) chars[s[i]-97]++;
		else chars[s[i]-65]++;
	}
	for(int i=0; i<26; i++){
		if(max != 0 && max == chars[i]){
			index = -1;
		}
		else if(chars[i] > max){
			max = chars[i];
			index = i;
		}
	}
	if(index != -1) printf("%c", index+65);
	else printf("?");
	return 0;
}