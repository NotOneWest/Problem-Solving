#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main(){
	string s; cin>>s;
	int dcnt=0, ccnt=0, sum=1;
	for(int i=0; i<s.length(); i++){
		if(s[i] == 'd'){
			sum*=10-dcnt;
			dcnt=1;
			ccnt=0;
		}
		else{
			sum*=26-ccnt;
			ccnt=1;
			dcnt=0;
		}
	}
	printf("%d", sum);
	return 0;
}