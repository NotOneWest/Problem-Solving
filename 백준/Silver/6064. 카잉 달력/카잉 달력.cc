#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int gcd(int m, int n){
	if(m==0) return n;
	return gcd(n%m, m);
}

int lcm(int m, int n){
	return (n*m)/gcd(m,n);
}

int kaing(int m, int n, int x, int y, int limit){
	int i=1,j=1,k=1;
	while(i!=x){
		if(i<m) i++;
		else i=1;
		if(j<n) j++;
		else j=1;
		k++;
	}
	while(j!=y){
		if((j+m)<n) j+=m;
		else{
			j+=m;
			while(j>n){
				j-=n;
			}
		}
		k+=m;
		if(k>limit) return -1;
	}
	return k;
}

int main(){
	int t; cin >> t;
	for(int i=0; i<t; i++){
		int m,n,x,y; scanf("%d %d %d %d", &m, &n, &x, &y);
		printf("%d\n", kaing(m,n,x,y,lcm(m,n)));
	}
	return 0;
}