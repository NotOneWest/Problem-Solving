#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, cnt=0; cin >> n;
	for(int i=0; i<n; i++){
		string c="";
		char s[101]; cin >> s;
		for(int i=0; i<strlen(s); i++){
			if(c[c.size()-1] != s[i]){
				if(c.find(s[i]) == string::npos) c+=s[i];
			}
			else c+=s[i];	
		}
		if(c.size() == strlen(s)) cnt++;
	}
	printf("%d", cnt);
	return 0;
}