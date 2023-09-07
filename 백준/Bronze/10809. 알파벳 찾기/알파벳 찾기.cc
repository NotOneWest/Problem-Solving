#include <bits/stdc++.h>
using namespace std;

int main(){
	string s; cin >> s;
	int loc[26] = {0,}, size = s.size();
	
	for(int i=0; i<26; i++) loc[i] = -1;
	for(int i=0; i<size; i++){
		if(loc[s[i]-97] == -1) loc[s[i]-97] = i;
	}
	for(int i=0; i<26; i++) printf("%d ", loc[i]);
	return 0;
}