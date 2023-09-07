#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int team[101], share[101];

int main(){
	int n,k; cin >> n >> k;
	for(int i=0; i<n; i++) cin >> share[i];
	for(int i=0; i<n; i++) cin >> team[i];
	for(int i=0; i<=k; i++){
		int index=0;
		int max=-100000001;
		for(int j=0; j<n; j++){
			for(int x=0; x<n-i; x++){ // 맨뒤에서 i번째 앞까지 조사. 
				if((share[j]*team[x])>max){
					max = share[j]*team[x];
					index=x; // 견제할 카드 위치 
				}
			}
		}
		if(i==k){
			cout << max;
			break;
		}
		team[index] = team[n-1-i]; // 견제한 카드를 맨뒤와 바꿔주고, 맨 뒤에서 앞까지만 조사함. 
	}
	return 0;
}
