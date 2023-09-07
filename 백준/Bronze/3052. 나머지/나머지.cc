#include <bits/stdc++.h>
using namespace std;

int main(){
	int num[10];
	for(int i=0; i<10; i++) scanf("%d", &num[i]);
	set<int> s;
	for(int i=0; i<10; i++) s.insert(num[i]%42);
	printf("%d", s.size());
	return 0;	
}