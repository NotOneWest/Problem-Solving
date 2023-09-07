#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int chang=100, sang=100;
    for(int i=0; i<n; i++) {
    	int c,s; cin >> c >> s;
		if(c > s) sang-=c;
		else if (c < s) chang-=s;
	}
	printf("%d\n", chang);
	printf("%d", sang);
    return 0;
}