#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int year(int e, int s, int m){
	int x=1,y=1,z=1,k=1;
	while(x!=e){
		x++;
		y++;
		z++;
		k++;
	}
	while(z!=m){
		if((y+15)<28) y+=15;
		else{
			y+=15;
			while(y>28){
				y-=28;
			}
		}
		if((z+15)<19) z+=15;
		else{
			z+=15;
			while(z>19){
				z-=19;
			}
		}
		k+=15;
	}
	while(y!=s){
		y+=285;
		while(y>28){
			y-=28;
		}
		k+=285;
	}
	return k;
}
int main(){
	int e,s,m; cin >> e >> s >> m;
	cout << year(e,s,m);
	return 0;
}