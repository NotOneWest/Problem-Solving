#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double PI = acos(-1);

int channel[10]={0,};

int check(string curr){
	int push=0;
	for(int i=0; i<curr.length(); i++){
		if(channel[curr[i]-'0']==-1){
			push=-1;
			break;
		}
		else push++;
	}
	return push;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string n="";
	int m,prev=0; cin >> n >> m;
	for(int i=0; i<m; i++){
		int c; cin >> c;
		channel[c]=-1;
	}
	int ans=abs(stoi(n)-100);
	if(m==0) (ans > n.length()) ? ans=n.length() : ans=ans;
	else{
		while(prev<1000001){
			if(check(to_string(prev))!=-1) ans=min(ans, abs(prev-stoi(n))+check(to_string(prev)));
			prev++;
		}
	}
	cout << ans << '\n';
	return 0;
}

