#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int main(){
	int num[9], sum=0 ,check=0;
	for(int i=0; i<9; i++){
		int n; cin >> n;
		num[i]=n;
		sum+=n;
	}
	sum-=100;
	sort(num, num+9);
	for(int i=0; i<9; i++){
		for(int j=i+1; j<9; j++){
			if((num[i] + num[j]) == sum){
				num[i]=0;
				num[j]=0;
				check=1;
				break;
			}
		}
		if(check == 1) break;
	}
	for(auto i : num){
		if(i != 0) cout << i << '\n';
	}
	return 0;
}
