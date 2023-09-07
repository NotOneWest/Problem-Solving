#include <bits/stdc++.h>
using namespace std;

int main(){
	string a,b,c="",d="";
	cin >>a >>b;
	for(int i=2; i>=0; i--){
		c+=a[i];
		d+=b[i];
	}
	
	if(atoi(c.c_str()) > atoi(d.c_str())) printf("%s", c.c_str());
	else printf("%s", d.c_str());
	return 0;
}