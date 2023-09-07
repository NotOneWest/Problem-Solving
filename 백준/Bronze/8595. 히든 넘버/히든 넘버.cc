#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main(){
	int n; cin>>n;
	string str, hn; cin>>str;
	long long sum=0;
	for(int i=0; i<n; i++){
		if(str[i] > 47 && str[i] < 58){
			hn += str[i];
		}
		else{
			sum += atoi(hn.c_str());
			hn = "";
		}
	}
	
	printf("%lld", sum+atoi(hn.c_str()));
	return 0;
}