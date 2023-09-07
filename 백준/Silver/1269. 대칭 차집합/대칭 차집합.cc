#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main(){
	int A,B;
	scanf("%d %d", &A, &B);
	vector<int> va, vsame;
	
	for(int i=0; i<A; i++){
		int put; cin>>put;
		va.push_back(put);
	}
	sort(va.begin(), va.end());
	
	for(int i=0; i<B; i++){
		int put; cin>>put;
		if(binary_search(va.begin(), va.end(), put)) vsame.push_back(put);
		
	}
	
	printf("%d", A+B-vsame.size()*2);
	
	return 0;
}