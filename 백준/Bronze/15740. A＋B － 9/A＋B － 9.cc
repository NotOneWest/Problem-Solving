#include <bits/stdc++.h>
using namespace std;

int main(){
	string a,b,res;
	cin >> a >> b;
	
	if(a >= to_string(-pow(2,60)) && a <= to_string(pow(2,60)) && b >= to_string(-pow(2,60)) && b <= to_string(pow(2,60))){
		printf("%lld", atoll(a.c_str()) + atoll(b.c_str()));
	}
	else{
		int size = a.size(), carry = 0;
		if(size > b.size()){
			int size2 = b.size();
			for(int i=0; i<size-size2; i++) b = '0' + b;
		}
		else if(size < b.size()) {
			for(int i=0; i<b.size()-size; i++) a = '0' + a;
			size = b.size();
		}
		for(int i=size-1; i>=0; i--){
			string c;
			c = to_string(a[i] + b[i] - '0' - '0' + carry);
			if(c.size() == 2){
				carry = c[0]-'0';
				res = c[1] + res;
			}
			else{
				res = c[0] + res;
				carry = 0;
			}
		}
		if (carry == 1) res = to_string(carry) + res;
		
		printf("%s", res.c_str());	
	}
	return 0;	
}