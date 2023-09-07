#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end();

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int main(){
	string s; cin >> s;
	int num[10]={0,}, set=0, set_check=0;
	for(int i=0; i<s.size(); i++) num[s[i]-'0']++;
	for(int i=0; i<10; i++){
		if(i !=6 && i != 9){
			if(num[i] > set_check){
				set+=(num[i]-set_check);
				set_check=set;
			}
		}
	}
	if( (num[6]+num[9]) > set_check*2 ){
		set += ((num[6]+num[9])-set_check*2)/2;
		set += ((num[6]+num[9])-set_check*2)%2;
	}
	printf("%d", set);
	return 0;
}