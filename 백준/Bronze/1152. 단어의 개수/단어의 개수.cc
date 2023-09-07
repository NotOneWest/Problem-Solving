#include <bits/stdc++.h>
using namespace std;

int main(){
	char s[1000001];
	cin.getline(s, 1000001, '\n');
	int count=0, size=strlen(s);
	for(int i=1; i<size-1; i++){
		if(s[i] == ' ') count++;
	}
	if(size == 1 && s[0] == ' ') count = -1;
	printf("%d", count+1);
	return 0;
}