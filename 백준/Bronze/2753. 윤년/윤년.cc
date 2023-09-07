#include <bits/stdc++.h>
using namespace std;

int main(){
	int year;
	cin >> year;
	
	
	if(year%400 == 0) printf("1");
	else if(year%4 == 0 && year%100 != 0) printf("1");
	else printf("0");
	
	return 0;
}