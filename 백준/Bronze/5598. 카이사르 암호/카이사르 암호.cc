#include <string>
#include <iostream>
using namespace std;

int main(){
	string caesar; cin>>caesar;
	
	for(int i=0; i<caesar.length(); i++){
		if(caesar[i] < 68) caesar[i] += 23;
		else caesar[i]-=3;
	}
	
	printf("%s", caesar.c_str());
	return 0;
}