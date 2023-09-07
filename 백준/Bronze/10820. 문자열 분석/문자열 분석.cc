#include <iostream>
#include <cstring>
using namespace std;

int main(){
	for(int i=0; i<100; i++){
		char s[101];
		cin.getline(s,101,'\n');
		if(strlen(s) == 0) break;
		int big=0, small=0, num=0, empty=0;
		for(int j=0; j<strlen(s); j++){
			if(s[j] > 64 && s[j] < 91) big++;
			else if(s[j] > 96 && s[j] < 123) small++;
			else if(s[j] > 47 && s[j] < 58) num++;
			else empty++;
		}
		printf("%d %d %d %d\n", small, big, num, empty); 
	}
	return 0;
}