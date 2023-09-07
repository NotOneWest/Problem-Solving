#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int button[1000001];

int main(){
	int n; cin >> n;
	for(int i=0; i<n; i++) cin >> button[i];
	int cnt=0;
	for(int i=0; i<n; i++){
		if(button[i]==1){
			cnt++;
			for(int j=0; j<3; j++){ // 자신과 앞 둑개의 버튼 눌러줌. 
				if((i+j)<n){
					if(button[i+j]==1) button[i+j]=0;
					else button[i+j]=1;	
				}
			}
		}
	}
	cout << cnt;
	return 0;
}
// 다 0인 상태에서 원하는 상태로 만드는 횟수 = 원하는 상태에서 다 0 만드는 횟수. 