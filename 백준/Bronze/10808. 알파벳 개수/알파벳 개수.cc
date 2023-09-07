#include <bits/stdc++.h>
using namespace std;

int main(){
	string s; cin >> s;
	int size = s.size(), alpabet[26]={0,}; 
	for(int i=0; i<size; i++) alpabet[s[i]-97]++;
	for(int i=0; i<26; i++) printf("%d ", alpabet[i]);
	return 0;
}