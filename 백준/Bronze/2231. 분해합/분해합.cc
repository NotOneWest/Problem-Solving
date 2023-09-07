#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int main(){
	int n,check=0; cin >> n;
	for(int i=1; i<=1000000; i++){
		string s=to_string(i);
		int size=s.size(), m=i;
		for(int j=0; j<size; j++){
			m+=(s[j]-'0');
		}
		if(m==n){
			printf("%d", i);
			check=1;
			break;
		}
	}
	if(check==0) printf("0");
	return 0;
}
