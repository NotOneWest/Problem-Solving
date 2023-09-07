#include <bits/stdc++.h>
using namespace std;

int main(){
	int a, b, c, i=1;
	cin >> a >> b >> c;
	
	if(b >= c) i = -1;
	else i += a/(c-b);
	printf("%d", i);
	
	return 0;
}