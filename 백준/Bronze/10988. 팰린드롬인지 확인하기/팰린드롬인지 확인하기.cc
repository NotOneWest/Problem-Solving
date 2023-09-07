#include <string>
#include <iostream>
using namespace std;

int main(){
	string word; cin>>word;
	int len = word.length(), check = 0;
	for(int i=0; i<len/2; i++){
		if(word[i] == word[len-1-i]) check = 1;
		else{
			check = 0;
			break;
		}
	}
	if(len==1) check = 1;
	printf("%d", check);
	return 0;
}