#include <bits/stdc++.h>
using namespace std;

int main(){
	long long rock; cin >> rock;
	int routine[7] = {1,0,1,1,1,1,0};
	if(routine[ rock%7-1 ] == 1) printf("SK");
	else printf("CY");
}