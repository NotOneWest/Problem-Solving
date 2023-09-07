#include <bits/stdc++.h>
using namespace std;

int main(){
	int a,b,c,num[10]={0,};
	cin >> a >> b >> c;
	string mul = to_string(a*b*c);
	int size = mul.length();
	for(int i=0; i<size; i++) num[mul[i]-48]++;
	for(int i=0; i<10; i++) printf("%d\n", num[i]);
	return 0;	
}