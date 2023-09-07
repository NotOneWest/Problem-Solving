#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int order[101], plug[101]={0,};

int main(){
	int n,k,cnt=0; cin >> n >> k;
	for(int i=0; i<k; i++) cin >> order[i];
	for(int i=0; i<k; i++){
		int check=0;
		for(int j=0; j<n; j++){ // 이미 꽂혀있는지 확인.
			if(plug[j]==order[i]){
				check=1;
				break;
			}
		}
		if(check) continue;
		for(int j=0; j<n; j++){ // 비어있으면 사용.
			if(plug[j]==0){
				plug[j]=order[i];
				check=1;
				break;
			}
		}
		if(check) continue;
		// 사용안되는 인덱스 찾아야함.
		int unusingidx, bigunsame=-1;
		for(int j=0; j<n; j++){
			int unsamenum=0;
			for(int p=i+1; p<k; p++){
				if(plug[j]==order[p]) break;
				unsamenum++; // 뒤의 스케줄과 다른 개수 체크
			}
			if(unsamenum>bigunsame){ // 다른 개수가 제일 큰 넘이 사용 안되는 넘이다.
				unusingidx=j;
				bigunsame=unsamenum;
			}
		}
		plug[unusingidx]=order[i]; // 사용 안되는 넘을 뽑고 바꿔줌.
		cnt++; // 뽑은 횟수 체크
	}
	cout << cnt;
	return 0;
}