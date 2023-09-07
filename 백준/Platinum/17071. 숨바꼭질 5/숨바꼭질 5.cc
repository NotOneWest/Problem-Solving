#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int odd[500002], even[500002], cnt=0;
queue<int> q;

void bfs(int n){
	q.push(n);
	even[n]=0;
	while(!q.empty()){
		int size = q.size();
		for(int i=0; i<size; i++){
			int temp = q.front();
			int dt[3]={temp-1, temp+1, temp*2};
			for(int p=0; p<3; p++){
				if(0<=dt[p] && dt[p]<=500000){
					if(cnt%2!=0){
						if(even[dt[p]]==0){
							q.push(dt[p]);
							even[dt[p]]=cnt+1;
						}
					}
					else{
						if(odd[dt[p]]==0){
							q.push(dt[p]);
							odd[dt[p]]=cnt+1;
						}
					}	
				}
			}
			q.pop();
		}
		cnt++;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,k,z=0,sec=500000; cin >> n >> k;
	bfs(n);
	if(n==k) sec=0;
	while(k<=500000){
		if(z%2==0){
			if(even[k]<=z && even[k]>0) sec = min(sec,z);
		}
		else{
			if(odd[k]<=z && odd[k]>0) sec = min(sec,z);
		}
		z++;
		k+=z;
	}
	if(sec == 500000) sec=-1;
	cout << sec;
	return 0;
}